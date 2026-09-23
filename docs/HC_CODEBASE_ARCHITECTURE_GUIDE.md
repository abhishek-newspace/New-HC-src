# Helios Hand Controller (HC) — Codebase Architecture & Flow Guide

**Audience:** Engineers who have never seen this repository.  
**Firmware version:** `0.0.3` (`src/single_hand_controller/include/definitions/version.h`)  
**Authoritative pin map:** `src/single_hand_controller/include/definitions/IO_defs.h` (prefer this over older SRS extracts if they disagree)  
**Last aligned to code:** September 2026

---

## Table of contents

1. [What this project is](#1-what-this-project-is)
2. [Big picture — how the system fits together](#2-big-picture--how-the-system-fits-together)
3. [Repository map — what lives where](#3-repository-map--what-lives-where)
4. [Module responsibilities — which file does what](#4-module-responsibilities--which-file-does-what)
5. [Firmware lifecycle (boot → wakeup → OFP)](#5-firmware-lifecycle-boot--wakeup--ofp)
6. [The request pattern (how every operator action works)](#6-the-request-pattern-how-every-operator-action-works)
7. [End-to-end flows by HC functionality](#7-end-to-end-flows-by-hc-functionality)
8. [MAVLink message catalog](#8-mavlink-message-catalog)
9. [Physical controls → pins → code](#9-physical-controls--pins--code)
10. [Display / HMI](#10-display--hmi)
11. [Configuration & compile modes](#11-configuration--compile-modes)
12. [Error codes](#12-error-codes)
13. [How to navigate the code as a newcomer](#13-how-to-navigate-the-code-as-a-newcomer)
14. [Related docs](#14-related-docs)

---

## 1. What this project is

This repository is **embedded firmware** for the **Single Hand Controller (HC)** used on the **Scout TD0** UGV in **Mode A** (proximal remote teleoperation, typically within ~10 m).

| Term | Meaning |
|------|---------|
| **HC / Helios-HC** | Hand Controller — the physical remote the operator holds |
| **Scout TD0** | The unmanned ground vehicle (UGV) platform |
| **Mode A** | Close-range teleop mode that this HC supports |
| **Atlas (MC)** | Mission computer on the UGV; HC’s MAVLink peer |
| **OFP** | Operational Flight Program — the 20 ms control loop while connected |
| **RFD / UHF** | Radio link (e.g. RFD900x) between HC Mega and Scout |

**It is not** a web app, cloud service, or multi-process backend. There are no HTTP APIs, databases, or message queues. Everything runs on one **Arduino Mega 2560** in `setup()` / `loop()`.

**What the operator can do with this firmware:**

- Drive Scout with the joystick (when armed)
- Arm / disarm
- Change drive mode and speed limit
- Control lights
- Engage / clear remote e-stop
- See connectivity, RSSI, UGV battery, HC battery, and errors on the TFT

---

## 2. Big picture — how the system fits together

```mermaid
flowchart LR
  subgraph Operator
    Stick[Joystick]
    Btns[Buttons / toggles]
    Eyes[TFT display]
  end

  subgraph HC["Arduino Mega 2560 — Helios-HC firmware"]
    IO[IOhandler]
    OFP[standard_procedures OFP]
    State[stateHandler]
    Disp[displayHandler]
    PH[packetHandler]
    TX[message_sender]
    RX[packet_receiver]
  end

  subgraph Link
    RadioHC[RFD radio on HC]
    RF[UHF air link]
    RadioScout[RFD radio on Scout]
  end

  Atlas[Atlas on Scout]

  Stick --> IO
  Btns --> IO
  IO --> OFP
  OFP --> PH
  PH --> TX
  TX --> RadioHC
  RadioHC --> RF --> RadioScout --> Atlas
  Atlas --> RadioScout --> RF --> RadioHC
  RadioHC --> PH
  PH --> RX
  RX --> State
  State --> Disp
  Disp --> Eyes
  RadioHC -. RADIO_STATUS .-> PH
```

### Production vs lab link

| Mode | How MAVLink travels | Config |
|------|---------------------|--------|
| **Production** | Mega **Serial3** → HC RFD → RF → Scout RFD → Atlas | `RELEASE` on, `HC_LINK_OVER_USB` off |
| **Lab / USB** | Mega **USB Serial** directly to Atlas (no radio) | `HC_LINK_OVER_USB` on |

Only file to switch: `src/single_hand_controller/include/definitions.h` (see [§11](#11-configuration--compile-modes)).

---

## 3. Repository map — what lives where

```
scout-td0-HC/
├── README.md                          # Clone → build → flash → verify
├── flash_code.sh / import_build.sh /  # Flash & hex helpers
│   check_version_change.sh
├── Build/                             # Prebuilt .hex artifacts
├── docs/                              # Architecture / SRS / link notes
│   └── HC_CODEBASE_ARCHITECTURE_GUIDE.md   ← this file
└── src/
    ├── readme.md                      # Contributor how-to (add modes, MAVLink, IO)
    ├── error_handling.md              # On-screen error meanings
    ├── ugvcustom.xml                  # MAVLink dialect ICD source
    ├── Doxyfile                       # Doxygen config
    └── single_hand_controller/        # ★ Arduino sketch root
        ├── single_hand_controller.ino # Entry: setup() / loop()
        ├── *.cpp                      # Application modules
        ├── include/                   # Headers + definitions + MAVLink
        ├── libraries/TFT_22_ILI9225/  # Display library (must stay next to .ino)
        └── arduino/                   # Vendored AVR toolchain (mostly Linux)
```

**Sketch path (open this in Arduino IDE):**  
`src/single_hand_controller/single_hand_controller.ino`

**Sketchbook location must be:**  
`…/src/single_hand_controller` (so `libraries/` resolves).

---

## 4. Module responsibilities — which file does what

Think of the firmware as layers. Data always moves **operator → IO flags → OFP → MAVLink TX**, and **MAVLink RX → packet_receiver → stateHandler → display**.

```mermaid
flowchart TB
  subgraph Entry
    INO["single_hand_controller.ino\nsetup / loop"]
  end

  subgraph Lifecycle
    SP["standard_procedures.cpp\nwakeup, OFP, pending timeouts"]
    PA["periodicActions.cpp\n1 Hz HB, 2 s display, timesync"]
    TM["timer.cpp\ninterval helpers"]
  end

  subgraph Operator_IO
    IO["IOhandler.cpp\nbuttons, toggles, joystick, HC battery ADC"]
    SETUP["setupFunctions.cpp\npin + display + MAVLink init"]
  end

  subgraph State_UI
    ST["stateHandler.cpp\nRAM mirrors of UGV/HC state"]
    DISP["displayHandler.cpp\nTFT drawing"]
  end

  subgraph Comms
    PH["packetHandler.cpp\nUART + send* + RX switch"]
    MS["message_sender.cpp\npack TX structs → buffer"]
    PR["packet_receiver.cpp\ndecode HEARTBEAT / TIMESYNC / RADIO_STATUS"]
    MSG["message_structs.h\nTX/RX layouts + command IDs"]
  end

  subgraph Config
    DEF["definitions.h + definitions/*.h\npins, times, enums, errors, version"]
    MAV["include/custom_v0.3/\ngenerated MAVLink C++11"]
    RADIO["radio_config.cpp\nRFD AT-command mode only"]
  end

  INO --> SETUP
  INO --> SP
  SP --> IO
  SP --> PH
  SP --> PA
  PH --> MS
  PH --> PR
  PR --> ST
  ST --> DISP
  IO -.->|sets request flags| SP
  DEF --> INO
  MAV --> MS
  MAV --> PR
```

| File | Responsibility |
|------|----------------|
| `single_hand_controller.ino` | Boot once; decide wakeup vs OFP; special compile modes |
| `standard_procedures.cpp` | Connectivity, timesync, **OFP cycle**, pending-request timeouts |
| `IOhandler.cpp` | Poll GPIO; set `arm_press`, `switchMode`, `estop_toggled`, etc. |
| `stateHandler.cpp` | Own all mutable state (UGV armed, speed, drive mode, e-stop, lights, connectivity) |
| `displayHandler.cpp` | Draw TFT (status, RSSI, batteries, errors, info text) |
| `packetHandler.cpp` | Open `RADIO_PORT`, `sendBuffer`, all `send*()` APIs, `handlePacketReceived()` |
| `message_sender.cpp` | Fill ICD structs and pack MAVLink into `buf[]` |
| `packet_receiver.cpp` | Interpret RX messages; update state / signing clock / RSSI |
| `message_structs.h` | Structs and command IDs shared by sender/receiver |
| `periodicActions.cpp` | Linked list of “call this every N ms” actions |
| `setupFunctions.cpp` | `setupIO()`, `setupDisplay()`, `initMAVLink()` |
| `radio_config.cpp` | Only when `GET_RADIO_CONFIG` — configure RFD via `+++` AT commands |
| `include/definitions.h` | Master compile switches (release, USB link, signing, ICD params) |
| `include/definitions/IO_defs.h` | Pin numbers, joystick deadzone, battery ADC |
| `include/definitions/time_defs.h` | OFP 20 ms, heartbeat timeout 3 s, e-stop retransmit 1 s, etc. |
| `include/includes.h` | Central include graph for the sketch |

---

## 5. Firmware lifecycle (boot → wakeup → OFP)

### 5.1 High-level state machine

```mermaid
stateDiagram-v2
  [*] --> Setup: Power ON / reset
  Setup --> Loop: setup() done

  state Loop {
    [*] --> CheckSpecialModes
    CheckSpecialModes --> RadioConfig: GET_RADIO_CONFIG
    CheckSpecialModes --> JoystickTest: TESTING_JOYSTICK
    CheckSpecialModes --> WakeupGate: normal

    RadioConfig --> [*]: stuck in performConfig()
    JoystickTest --> [*]: stuck dumping stick

    WakeupGate --> Wakeup: heartbeat timed out
    WakeupGate --> OFP: UGV connected
    Wakeup --> EstablishConnectivity
    EstablishConnectivity --> TimeSync: Atlas HEARTBEAT seen
    TimeSync --> OFP: timesync OK or Error 7 shown
    OFP --> WakeupGate: HEARTBEAT lost (>3 s)
  }
```

### 5.2 `setup()` — what runs once

**File:** `single_hand_controller.ino`

```mermaid
sequenceDiagram
  participant MCU as Mega bootloader
  participant INO as single_hand_controller.ino
  participant SF as setupFunctions
  participant PH as packetHandler
  participant DISP as displayHandler

  MCU->>INO: setup()
  INO->>SF: setupIO() — pin modes
  INO->>SF: setupDisplay() — TFT splash / chrome
  INO->>PH: initMAVLink() — Serial + signing
  alt signing failed
    INO->>DISP: displayError(..., SIGNING_FAIL)
  end
  INO->>PH: sendHeartbeat() × 3
  Note over PH: Prompts local RFD to emit RADIO_STATUS
```

### 5.3 `loop()` → wakeup → OFP

**Files:** `single_hand_controller.ino`, `standard_procedures.cpp`

```mermaid
flowchart TD
  A[loop] --> B{heartbeat_timed_out?}
  B -->|yes| C[run_wakeup_seq]
  C --> C1[periodic: HB 1 Hz + display 2 s]
  C1 --> C2[establish_connectivity]
  C2 --> C2a[Wait for Atlas HEARTBEAT]
  C2a --> C2b{RADIO_STATUS seen?\nskip if USB mode}
  C2b -->|no after 5 s| E5[Error 5 on TFT]
  C2b -->|yes / USB| C3[time_synchronize]
  C3 --> C3a[TIMESYNC request every 1 s]
  C3a --> C3b{response?}
  C3b -->|no| E7[Error 7]
  C3b -->|yes| C4[reset periodics for OFP]
  C4 --> D
  B -->|no| D{isUGV_connected?}
  D -->|no| A
  D -->|yes| E[while true: run_OFP_cycle]
  E --> F{still connected?}
  F -->|no| A
  F -->|yes| E
```

### 5.4 One OFP cycle (20 ms) — the heart of teleop

**File:** `standard_procedures.cpp` → `run_OFP_cycle()`  
**Period:** `OFP_LOOP_TIME` = **20 ms** (`time_defs.h`)

```mermaid
flowchart TD
  Start([startOFPTimer]) --> Sample[checkUserInput — GPIO → flags]
  Sample --> HB{heartbeat timed out?}
  HB -->|yes| Disc[set UGV disconnected + return]
  HB -->|no| Armed{UGV state == active?}
  Armed -->|yes| MC[sendManualControl]
  Armed -->|no| Cmds
  MC --> Cmds

  subgraph Cmds [Operator command TX]
    direction TB
    A1{arm_press + standby?} -->|yes| Arm[sendArmCommand + pending ARM]
    A1 -->|no| A2{arm_press + active?}
    A2 -->|yes| Disarm[sendDisarmCommand + pending DISARM]
    A2 --> Estop
    Estop{estop engage/clear flags} --> EstopTX[sendEstopRequest @ 1 Hz until HB confirms]
    Lights{light edge flags} --> LightTX[sendLightToggleState once]
    Speed{speed_limit_press?} -->|yes| SpTX[sendSpeedChangeRequest + pending]
    Mode{switchMode?} -->|yes| MdTX[sendModeChangeRequest + pending]
  end

  Cmds --> RX[handlePacketReceived]
  RX --> Pend[evaluatePendingRequests — 3 s timeout]
  Pend --> Per[periodic_actions: HB / display / timesync-if-disc]
  Per --> Wait[end_OFP_timer — busy-wait + keep sampling IO]
  Wait --> Start
```

**Pin → OFP mapping (current firmware):**

| Pin | Control | OFP flag / action |
|-----|---------|-------------------|
| A0 / A1 | Joystick | `sendManualControl` when armed |
| 2 | Arm button (long-press) | `arm_press` → ARM or DISARM |
| 3 | Speed limit (hold 3 s) | `speed_limit_press` → cycle Low→Mid→High |
| 4 / 5 | E-stop 3-pos toggle | `estop_toggled` / `estop_clear_request` |
| 6 / 8 | Lights 3-pos toggle | `turnOffLight` / `turnOnHeadlight` / `turnOnFoglight` |
| 7 | Drive mode | `switchMode` |

---

## 6. The request pattern (how every operator action works)

Almost every state change follows the same design (documented in `src/readme.md`):

```mermaid
sequenceDiagram
  participant Op as Operator
  participant IO as IOhandler.cpp
  participant SP as standard_procedures.cpp
  participant PH as packetHandler.cpp
  participant Atlas as Atlas
  participant PR as packet_receiver.cpp
  participant ST as stateHandler.cpp
  participant UI as displayHandler.cpp

  Op->>IO: press / toggle
  IO->>SP: set flag e.g. switchMode = true
  Note over SP: Next OFP tick
  SP->>PH: sendModeChangeRequest()
  SP->>SP: startPendingRequest(PENDING_DRIVE_MODE)
  SP->>UI: displayInfo("setting drive mode ...")
  PH->>Atlas: COMMAND_LONG over radio/USB
  Atlas-->>PH: HEARTBEAT (custom_mode bits updated)
  PH->>PR: receive_heartbeat()
  PR->>ST: switchDriveMode / setUGV_speed / setUGV_state / ...
  ST->>UI: displayDriveMode / etc.
  SP->>SP: evaluatePendingRequests — clear if matched<br/>else Error/Info after 3 s
```

**Why HEARTBEAT instead of COMMAND_ACK?**  
Current production confirmation path uses Atlas **HEARTBEAT `custom_mode` bitfields**. Pending requests time out at **3 seconds** (`STATE_REQUEST_TIMEOUT_MS`) and show Error 3 (arm) or info text (speed / drive mode).

**Flags live in** `standard_procedures.cpp` and are declared `extern` in `IOhandler.cpp`.

---

## 7. End-to-end flows by HC functionality

Each subsection is independent: you can read only the feature you care about.

---

### 7.1 Connectivity, radio health, and timesync

**Purpose:** Know Scout is reachable, radio is healthy, clocks align (needed for MAVLink signing).

**Key files:** `standard_procedures.cpp`, `packet_receiver.cpp`, `packetHandler.cpp`, `stateHandler.cpp`, `displayHandler.cpp`

```mermaid
flowchart LR
  subgraph HC_TX
    HB1[HC HEARTBEAT 1 Hz]
    TS1[TIMESYNC request]
  end
  subgraph Local_radio
    RS[RADIO_STATUS msgid 109]
  end
  subgraph Atlas_RX_path
    HB2[Atlas HEARTBEAT]
    TS2[TIMESYNC response]
  end

  HB1 --> Link[RADIO_PORT]
  TS1 --> Link
  Link --> Atlas
  Atlas --> HB2 --> PR[packet_receiver]
  Atlas --> TS2 --> PR
  RFD[Local RFD] --> RS --> PR
  PR --> ST[connectivity / RSSI / signing clock]
  ST --> UI[conn LED + RSSI]
```

| Step | What happens | Where |
|------|----------------|-------|
| 1 | HC sends HEARTBEAT every 1 s | `sendHeartbeat` via `periodicActions` |
| 2 | Local RFD injects `RADIO_STATUS` | `receive_radio_status` — RSSI, txbuf; Error 5/6 |
| 3 | Atlas HEARTBEAT within 3 s | Clears timeout; `last_heartbeat_received_at` |
| 4 | HC sends TIMESYNC; waits for reply | `time_synchronize`; seeds signing timestamp |
| 5 | Loss of HEARTBEAT > 3 s | UGV → `disconnected`; leave OFP; re-wakeup |

**Connectivity LED** (`enum_defs.h` / `displayHandler.cpp`):

| Status | Colour | Meaning |
|--------|--------|---------|
| `all_disconnected` / radio-only | Red | No UGV |
| `low_connectivity` | Yellow | Connected but weak RSSI |
| `connected` | Green | Healthy |
| `comm_fault` | Blue | Timesync fault |

**USB mode:** Error 5 (no `RADIO_STATUS`) is skipped (`RADIO_SIMULATION_TESTING`).

---

### 7.2 Manual teleoperation (joystick → drive)

**Purpose:** While armed (`ugv_status == active`), send stick axes to Atlas.

**Key files:** `IOhandler.cpp` (`getXY`), `packetHandler.cpp` (`sendManualControl`), `message_sender.cpp`, `standard_procedures.cpp`

```mermaid
sequenceDiagram
  participant Stick as Joystick A0/A1
  participant IO as getXY()
  participant OFP as run_OFP_cycle
  participant PH as sendManualControl
  participant Atlas as Atlas / drivetrain

  loop Every 20 ms while armed
    OFP->>IO: read ADC, deadzone, normalize (±~4800)
    OFP->>PH: if active
    Note over PH: MANUAL_CONTROL msgid 69
    alt MANUAL_CONTROL_ONLY_WHEN_MOVING
      PH-->>PH: skip if stick idle at center<br/>(still send one zero frame on release)
    end
    PH->>Atlas: x,y axes
  end
```

| Detail | Value / location |
|--------|------------------|
| Pins | A0 = X, A1 = Y (`IO_defs.h`) |
| Deadzone | `XY_LOWER_LIMIT` / `XY_UPPER_LIMIT` around mid ADC |
| Message | `MANUAL_CONTROL` (69) → Scout system ID |
| Gate | Only when `getUGV_state() == active` |
| Rate | OFP 20 ms (~50 Hz); optionally only when moving |

---

### 7.3 Arm / Disarm

**Purpose:** Enable or disable teleop authority on Scout.

**Key files:** `IOhandler.cpp` (long-press on pin 2), `standard_procedures.cpp`, `packetHandler.cpp`, `packet_receiver.cpp`, `message_structs.h`

```mermaid
flowchart TD
  A[Long-press ARM button pin 2] --> B[enableArm → arm_press = true]
  B --> C{OFP: UGV state?}
  C -->|standby| D[sendArmCommand]
  C -->|active| E[sendDisarmCommand]
  D --> F[COMMAND_LONG 400 param1=ICD_ARM_PARAM1=2]
  E --> G[COMMAND_LONG 400 param1=ICD_DISARM_PARAM1=1]
  F --> H[pending PENDING_ARM]
  G --> I[pending PENDING_DISARM]
  H --> J[Atlas HEARTBEAT arm bits]
  I --> J
  J --> K{arm field == 2?}
  K -->|yes| L[setUGV_state active]
  K -->|arm == 1| M[setUGV_state standby]
  L --> N[clear pending / clear info]
  M --> N
  H --> O{no confirm in 3 s?}
  I --> O
  O -->|yes| P[Error 3 Arm/Disarm Failure]
```

**Confirmation:** HEARTBEAT `custom_mode` arm field (`1` = standby/disarmed, `2` = active/armed) — see `receive_heartbeat()`.

---

### 7.4 Drive mode

**Purpose:** Cycle Scout drive mode (speed / torque / torque+speed-limit).

**Key files:** `IOhandler.cpp` (pin 7), `standard_procedures.cpp`, `packetHandler.cpp` (`sendModeChangeRequest`), `stateHandler.cpp`, `packet_receiver.cpp`

```mermaid
flowchart LR
  Btn[Press pin 7] --> Flag[switchMode = true]
  Flag --> OFP[OFP: sendModeChangeRequest]
  OFP --> CMD["COMMAND_LONG 31900\nMAV_CMD_DRIVE_MODE"]
  CMD --> Atlas
  Atlas --> HB[HEARTBEAT custom_mode bits 0–1]
  HB --> ST[switchDriveMode]
  ST --> UI[displayDriveMode]
```

Pending timeout → TFT info: `"Drive mode request timed out"`.

---

### 7.5 Speed limit

**Purpose:** Cycle Low → Mid → High speed limit.

**Key files:** `IOhandler.cpp` (`cycleSpeedLimit`, pin 3 hold 3 s), `standard_procedures.cpp`, `packetHandler.cpp` (`sendSpeedChangeRequest`)

```mermaid
flowchart TD
  Hold[Hold pin 3 for SPEED_LIMIT_HOLD_MS = 3 s] --> Cycle[cycleSpeedLimit]
  Cycle --> Flag[required_speed + speed_limit_press]
  Flag --> OFP[sendSpeedChangeRequest]
  OFP --> CMD["COMMAND_LONG 176\nMAV_CMD_DO_SET_MODE\nparam encodes 1/2/3"]
  CMD --> Atlas
  Atlas --> HB[HEARTBEAT speed bits]
  HB --> ST[setUGV_speed]
  ST --> UI[speed on display]
  OFP --> Pend{confirm in 3 s?}
  Pend -->|no| Info[Info: Speed limit request timed out]
```

No auto-retry after timeout; next 3 s hold sends the next limit.

---

### 7.6 Lights

**Purpose:** Set head / fog / off from a 3-position toggle (edge-triggered — one TX per change).

**Key files:** `IOhandler.cpp` (`updateLightToggleEdge`, pins 6/8), `packetHandler.cpp` (`sendLightToggleState`), `message_structs.h`

```mermaid
flowchart LR
  T{Toggle position}
  T -->|pin 6 OFF| Off[sendLightToggleState 0]
  T -->|centre HEAD| Head[sendLightToggleState 1]
  T -->|pin 8 FOG| Fog[sendLightToggleState 2]
  Off --> CMD["COMMAND_LONG 31901\nLIGHT_CONTROL\nICD: 0=OFF 1=ON\nparam1=head param2=fog param3=rear"]
  Head --> CMD
  Fog --> CMD
  CMD --> Atlas
```

| Toggle pos | Encoding in `sendLightToggleState` |
|------------|-------------------------------------|
| 0 OFF | head=0, fog=0, rear=0 |
| 1 HEAD (centre) | head=1, fog=0, rear=1 |
| 2 FOG | head=0, fog=1, rear=0 |

---

### 7.7 Remote emergency stop

**Purpose:** Engage or clear vehicle remote e-stop; retransmit until HEARTBEAT confirms.

**Key files:** `IOhandler.cpp` (pins 4/5), `standard_procedures.cpp`, `packetHandler.cpp` (`sendEstopRequest`), `stateHandler.cpp` (`switchEmergencyMode`)

```mermaid
flowchart TD
  Eng[Toggle pin 4 = engage] --> F1[estop_toggled = true]
  Dis[Toggle pin 5 = disengage] --> F2[estop_clear_request = true]
  Cen[Centre] --> NA[estopToggleNa — no TX]

  F1 --> Loop1{HEARTBEAT emergency == engaged?}
  Loop1 -->|no| TX1["sendEstopRequest true\nparam1=2 every ESTOP_RETRANSMIT_MS 1 s"]
  TX1 --> Loop1
  Loop1 -->|yes| Stop1[Stop TX]

  F2 --> Loop2{still engaged?}
  Loop2 -->|yes| TX2["sendEstopRequest false\nparam1=3 every 1 s"]
  TX2 --> Loop2
  Loop2 -->|no| Clear[clear estop_clear_request]

  HB[HEARTBEAT emergency field] --> UI[displayEstopStatus / Error 8 if engaged]
```

ICD param1 values (`definitions.h`): `1` Disable, `2` Engaged, `3` Disengaged. HC toggle uses 2 and 3.

---

### 7.8 Display / HMI updates

**Purpose:** Show operator status without blocking the OFP.

**Key files:** `displayHandler.cpp`, `display_defs.h`, `stateHandler.cpp`, `periodicActions` → `updateDisplay` every 2 s

```mermaid
flowchart TB
  subgraph Direct["Direct updates — call display* immediately"]
    D1[drive mode / e-stop / UGV status / errors / info]
  end
  subgraph Periodic["Periodic — updateDisplay every 2 s"]
    P1[battery gauges]
    P2[RSSI]
    P3[connectivity LED]
    P4[HC battery SoC]
  end
  ST[stateHandler setters] --> Direct
  ST --> Periodic
  PA[periodicActions] --> Periodic
```

**HC battery:** ADC A6 → local UI only; **never** sent on MAVLink (`readHcBatterySoc` in `IOhandler.cpp`).

---

### 7.9 Radio AT-command configuration (maintenance mode)

**Purpose:** Configure the RFD radio from the Mega (not part of normal teleop).

**Key files:** `radio_config.cpp`, compile flag `GET_RADIO_CONFIG` in `definitions.h`

```mermaid
flowchart LR
  Boot[setup] --> Loop
  Loop --> CFG[performConfig]
  CFG --> AT["Serial3 +++ AT command mode"]
  AT --> Stuck[while true — never enters OFP]
```

---

### 7.10 Packet TX/RX pipeline (shared by all features)

```mermaid
flowchart TB
  subgraph Send
    S1[sendXxx in packetHandler.cpp]
    S2[msgsndr.buffer_xxx in message_sender.cpp]
    S3[buf filled with MAVLink bytes]
    S4[sendBuffer → RADIO_PORT.write]
  end
  subgraph Receive
    R1[RADIO_PORT.available]
    R2[mavlink_parse_char]
    R3[switch msgid]
    R4[packet_receiver::receive_*]
    R5[stateHandler + display]
  end
  S1 --> S2 --> S3 --> S4 --> Air[UHF or USB]
  Air --> R1 --> R2 --> R3 --> R4 --> R5
```

**RX messages handled today** (`handlePacketReceived`):

| msgid | Handler |
|-------|---------|
| TIMESYNC (111) | `receive_timesync` |
| RADIO_STATUS (109) | `receive_radio_status` |
| HEARTBEAT (0) | `receive_heartbeat` |
| SYS_STATUS / COMMAND_ACK | Only if `DEPRECATED_REV_1` is **not** defined (secondary paths) |

**Not wired yet:** `UGV_SYSTEM_INFO` (50001) exists in dialect XML but has no RX case.

---

### 7.11 HEARTBEAT `custom_mode` decode (Atlas → HC status bus)

Atlas packs status into HEARTBEAT `custom_mode`. HC unpacks in `receive_heartbeat()`:

```mermaid
flowchart LR
  CM[custom_mode uint32] --> B0["bits 0–1: drive mode"]
  CM --> B1["bits 2–3: speed limit"]
  CM --> B2["bits 4–5: arm 1=standby 2=active"]
  CM --> B3["bits 6–7: emergency ICD 1/2/3"]
  CM --> B4["next 8 bits: UGV battery SoC"]
```

This is the **primary feedback channel** for arm, speed, drive mode, e-stop, and UGV battery.

---

## 8. MAVLink message catalog

**Dialect source:** `src/ugvcustom.xml` → generated headers under `include/custom_v0.3/`  
**IDs:** HC = system `2` / component `1`; Scout = `1`; Atlas component = `191`

| Direction | Message | ID / cmd | Sender / receiver in code |
|-----------|---------|----------|---------------------------|
| HC → Atlas | HEARTBEAT | 0 | `sendHeartbeat` / `buffer_heartbeat` |
| HC → Atlas | TIMESYNC | 111 | `sendTimesyncRequest` |
| HC → Atlas | MANUAL_CONTROL | 69 | `sendManualControl` |
| HC → Atlas | COMMAND_LONG ARM/DISARM | 76 / **400** | `sendArmCommand` / `sendDisarmCommand` |
| HC → Atlas | COMMAND_LONG DO_SET_MODE | 76 / **176** | `sendSpeedChangeRequest` |
| HC → Atlas | COMMAND_LONG DRIVE_MODE | 76 / **31900** | `sendModeChangeRequest` |
| HC → Atlas | COMMAND_LONG LIGHT_CONTROL | 76 / **31901** | `sendLightToggleState` |
| HC → Atlas | COMMAND_LONG REMOTE_EMERGENCY | 76 / **31904** | `sendEstopRequest` |
| Atlas → HC | HEARTBEAT | 0 | `receive_heartbeat` |
| Atlas → HC | TIMESYNC | 111 | `receive_timesync` |
| Radio → HC | RADIO_STATUS | 109 | `receive_radio_status` |

Optional signing: `SIGN_PACKETS` + `signing_key[]` in `definitions.h`; timesync seeds the signing clock.

---

## 9. Physical controls → pins → code

**Source of truth:** `IO_defs.h` + `IOhandler.cpp` (comments in `standard_procedures.cpp` match this map).

| Pin | Macro | Hardware | IO callback / flag | OFP / TX |
|-----|-------|----------|--------------------|----------|
| A0 | `XPIN` | Joystick X | `getXY` | `MANUAL_CONTROL` |
| A1 | `YPIN` | Joystick Y | `getXY` | `MANUAL_CONTROL` |
| 2 | `BUTTON_ARM` | Arm long-press | `enableArm` → `arm_press` | ARM/DISARM 400 |
| 3 | `BUTTON_SPEED_LIMIT` | Hold 3 s | `cycleSpeedLimit` → `speed_limit_press` | DO_SET_MODE 176 |
| 4 | `TOGGLE_ESTOP_ENGAGE` | E-stop engage | `engageEstop` | REMOTE_EMERGENCY param1=2 |
| 5 | `TOGGLE_ESTOP_DISENGAGE` | E-stop clear | `disengageEstop` | param1=3 |
| 6 | `TOGGLE_LIGHTS_OFF` | Lights OFF | `turnOffLights` | LIGHT_CONTROL |
| 7 | `BUTTON_TORQUE_MODE` | Drive mode | `enableSwitchMode` → `switchMode` | DRIVE_MODE 31900 |
| 8 | `TOGGLE_FOGLIGHTS` | Fog | `turnOnFoglights` | LIGHT_CONTROL |
| A6 | `HC_BATTERY_ADC_PIN` | HC pack sense | `readHcBatterySoc` | UI only |
| A2–A5, A7, A9 | TFT_* | ILI9225 | `displayHandler` | — |

> Older docs under `docs/HC_SRS_v1.4_TRACEABILITY.md` may show a different pin matrix. **Trust `IO_defs.h` for firmware behavior.**

---

## 10. Display / HMI

| Concern | File |
|---------|------|
| Draw APIs | `displayHandler.cpp` / `.hpp` |
| Colours, positions, layout | `definitions/display_defs.h` |
| When to refresh | Direct from `stateHandler`; periodic via `updateDisplay` (2 s) |
| Errors / info banners | `displayError`, `displayInfo`, `clearError`, `clearInfo` |
| Splash / static chrome | `setupDisplay`, `displayBasic` |

---

## 11. Configuration & compile modes

**Master file:** `src/single_hand_controller/include/definitions.h`

### Link mode (most common switch)

| Goal | `RELEASE` | `HC_LINK_OVER_USB` |
|------|-----------|--------------------|
| Production UHF | defined | undefined |
| Lab USB ↔ Atlas | undefined | defined |
| Radio + USB Serial Monitor debug | undefined | undefined (+ `_DEBUG_` ok) |

Details: `docs/HC_LINK_USB_VS_RADIO.md`

### Other useful defines

| Define | Effect |
|--------|--------|
| `SIGN_PACKETS` | Signed MAVLink |
| `MANUAL_CONTROL_ONLY_WHEN_MOVING` | Stick TX only when deflected (+ zero frame) |
| `GET_RADIO_CONFIG` | Boot into RFD AT config forever |
| `TESTING_JOYSTICK` | Dump stick forever |
| `TESTING` | Skip connectivity; jump toward OFP |
| `_DEBUG_` / `PRINT_BYTES` | Serial logging (do **not** use with USB MAVLink) |
| `STOP_COMM` / `STOP_RECV` | Mute TX or RX for IO bench testing |
| `ICD_ARM_PARAM1` / `ICD_DISARM_PARAM1` | 2 = arm, 1 = disarm |
| `ICD_REMOTE_EMERGENCY_*` | 1/2/3 e-stop params |

**Runtime config:** none. No `.env`, no EEPROM path in normal OFP. Everything is compile-time + RAM state.

---

## 12. Error codes

Defined in `definitions/error_codes.h`; operator meanings in `src/error_handling.md`.

| Code | Macro | Meaning |
|------|-------|---------|
| 1 | `SIGNING_FAIL` | Signing setup failed / disabled |
| 2 | `JOYSTICK_CALIBRATION` | Deprecated calibration path |
| 3 | `ARM_DISARM_FAIL` | Arm/disarm not confirmed in 3 s |
| 5 | `RADIO_COMM_FAILURE` | No local `RADIO_STATUS` (HC↔radio) |
| 6 | `RADIO_BUFFER_OVERLOAD` | Radio TX buffer nearly full |
| 7 | `TIME_SYNCHRONIZE_FAILED` | No timesync response from Scout |
| 8 | `ESTOP_ENGAGED` | E-stop engaged (informational) |

---

## 13. How to navigate the code as a newcomer

Use this path the first time you open the repo:

```mermaid
flowchart TD
  A[1. Read this guide §1–5] --> B[2. Open single_hand_controller.ino]
  B --> C[3. Follow setup → loop → run_wakeup_seq → run_OFP_cycle]
  C --> D[4. Pick one feature e.g. Arm]
  D --> E[IOhandler flag → OFP send* → packet_receiver HEARTBEAT → stateHandler → display]
  E --> F[5. Check definitions.h + IO_defs.h + time_defs.h for constants]
  F --> G[6. For new MAVLink/IO: follow recipes in src/readme.md]
```

**Mental model cheat sheet:**

| Question | Look here first |
|----------|-----------------|
| When does the loop start teleop? | `single_hand_controller.ino` + `run_wakeup_seq` |
| What happens every 20 ms? | `run_OFP_cycle` |
| Which pin is this button? | `IO_defs.h` |
| Who sets the request flag? | `IOhandler.cpp` |
| Who sends the MAVLink? | `packetHandler.cpp` → `message_sender.cpp` |
| Who applies Scout feedback? | `packet_receiver.cpp` → `stateHandler.cpp` |
| Who draws the screen? | `displayHandler.cpp` |
| What does Error N mean? | `error_handling.md` |

---

## 14. Related docs

| Document | Use it for |
|----------|------------|
| Root `README.md` | Build / flash / verify on Windows & Linux |
| `src/readme.md` | How to add modes, display items, MAVLink, IO |
| `src/error_handling.md` | Operator-facing error resolution |
| `docs/HC_LINK_USB_VS_RADIO.md` | USB vs UHF switch |
| `docs/HC_SRS_v1.4_TRACEABILITY.md` | SRS Mode A requirement status (pin table may lag code) |
| `src/ugvcustom.xml` | MAVLink ICD dialect source |

---

## Appendix A — Timing constants (quick reference)

From `time_defs.h`:

| Constant | Value | Role |
|----------|-------|------|
| `OFP_LOOP_TIME` | 20 ms | Teleop loop period |
| `HEARTBEAT_TIMEOUT` | 3 s | Declare disconnect |
| `STATE_REQUEST_TIMEOUT_MS` | 3 s | Arm/speed/mode pending fail |
| `ESTOP_RETRANSMIT_MS` | 1 s | E-stop retransmit while waiting confirm |
| `SPEED_LIMIT_HOLD_MS` | 3 s | Hold before speed cycle |
| `LONG_PRESS_DURATION` | 500 ms | Arm button long-press |
| Display period | 2 s | `updateDisplay` via periodic actions |
| HC heartbeat period | 1 s | While connected / wakeup |

---

## Appendix B — End-to-end “day in the life” of a session

```mermaid
sequenceDiagram
  actor Op as Operator
  participant HC as Helios-HC
  participant Radio as UHF radios
  participant Atlas as Atlas

  Op->>HC: Power ON
  HC->>HC: setupIO / setupDisplay / initMAVLink
  HC->>Radio: HEARTBEAT × 3
  HC->>HC: wakeup: wait Atlas HEARTBEAT + TIMESYNC
  Atlas-->>HC: HEARTBEAT + TIMESYNC
  HC->>HC: Enter OFP @ 20 ms

  Op->>HC: Long-press Arm
  HC->>Atlas: COMMAND_LONG 400 arm
  Atlas-->>HC: HEARTBEAT armed
  HC->>Op: UI shows active

  loop Driving
    Op->>HC: Move stick
    HC->>Atlas: MANUAL_CONTROL
  end

  Op->>HC: Toggle e-stop engage
  HC->>Atlas: REMOTE_EMERGENCY 2 @ 1 Hz until confirmed
  Atlas-->>HC: HEARTBEAT emergency engaged
  HC->>Op: Error 8 / e-stop UI

  Note over HC,Atlas: If HEARTBEAT lost > 3 s → disconnect → re-wakeup
```

---

*This guide describes the Hand Controller firmware as implemented in-tree. Peer systems (Atlas, VCU, Mode B, GCS) are outside this repository except as MAVLink endpoints.*
