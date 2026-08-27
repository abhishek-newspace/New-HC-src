# scout-td0-HC

Repository for the Single Hand Controller (HC) used in Mode A operation.

---

## Flash HC firmware (clone → build → flash)

Target board: **Arduino Mega 2560** (ATmega2560), flashed over USB with the stock bootloader (`avrdude`, protocol `wiring`, 115200 baud).

| Workflow | Description |
|----------|-------------|
| **Arduino IDE** | Build + upload in one click (GUI) — same on Windows and Linux |
| **CLI (no IDE GUI)** | **Arduino CLI** to compile + **avrdude** to flash a `.hex` |

> **Note:** The `avrdude` binary inside this repo (`src/single_hand_controller/arduino/tools/…`) is a **Linux** build. On **Windows** you must install **Arduino CLI** (or Arduino IDE) to get `avrdude.exe` and the AVR compiler.

---

## What you need (by operating system)

### Common (Windows and Linux)

| Item | Purpose |
|------|---------|
| [Git](https://git-scm.com/) | Clone the repository |
| USB cable | Connect HC Mega to your PC |
| HC serial port | See table below |

| OS | Typical HC port | How to find it |
|----|-----------------|----------------|
| **Windows** | `COM3`, `COM4`, … | Device Manager → Ports (COM & LPT), or `arduino-cli board list` |
| **Linux** | `/dev/ttyACM0`, `/dev/ttyUSB0` | `arduino-cli board list`, or `ls /dev/ttyACM*` |

**Before flashing:** close Serial Monitor, Atlas, or any app using that port.

---

### Windows — install once

| Tool | Required for | Install |
|------|--------------|---------|
| **Arduino CLI** | Build **and** flash without IDE | https://arduino.github.io/arduino-cli/latest/installation/ or `winget install ArduinoSA.CLI` |
| **Arduino IDE** (optional) | GUI build/upload instead of CLI | https://www.arduino.cc/en/software |

After installing Arduino CLI, open a **new** PowerShell window:

```powershell
arduino-cli version
arduino-cli config init
arduino-cli core update-index
arduino-cli core install arduino:avr
```

This installs the AVR compiler and **avrdude** under:

```
%LOCALAPPDATA%\Arduino15\packages\arduino\tools\
```

Example `avrdude` path (version folder may differ):

```
%LOCALAPPDATA%\Arduino15\packages\arduino\tools\avrdude\8.0.0-arduino1\bin\avrdude.exe
```

Find yours if needed:

```powershell
Get-ChildItem "$env:LOCALAPPDATA\Arduino15\packages\arduino\tools" -Recurse -Filter avrdude.exe
```

**Windows helper scripts:** `import_build.sh`, `flash_code.sh`, and `check_version_change.sh` are shell scripts for **Linux**. On Windows use the PowerShell commands in this README (or Git Bash).

---

### Linux — install once

| Tool | Required for | Install |
|------|--------------|---------|
| **Arduino CLI** or **Arduino IDE** | Build firmware | [Arduino CLI](https://arduino.github.io/arduino-cli/) or [Arduino IDE](https://www.arduino.cc/en/software) |
| **avrdude** | Flash `.hex` | Included with Arduino CLI / IDE, or `sudo apt install avrdude` |

Arduino CLI setup:

```bash
arduino-cli config init
arduino-cli core update-index
arduino-cli core install arduino:avr
```

After Arduino IDE compile, build cache is usually:

```
~/.cache/arduino/sketches/<hash>/single_hand_controller.ino.hex
```

**Linux helper scripts** (from repo root):

| Script | Purpose |
|--------|---------|
| `sh import_build.sh` | Copy latest IDE build cache into `Build/` |
| `sh flash_code.sh` | Flash hex from `Build/` (default port `/dev/ttyACM0`) |
| `sh check_version_change.sh` | Compare on-board flash vs `Build/` hex |

---

## Step 1 — Clone (Windows and Linux)

```bash
git clone https://github.com/newspaceresearch-ugv/scout-td0-HC.git
cd scout-td0-HC
```

Sketch path:

```
src/single_hand_controller/single_hand_controller.ino
```

The `libraries` folder must stay next to the `.ino` file (`src/single_hand_controller/libraries/`).

---

## Step 2 — Build the firmware

### Option A — Arduino IDE (Windows and Linux)

1. Open `src/single_hand_controller/single_hand_controller.ino`.
2. **File → Preferences** → **Sketchbook location** = full path to:

   ```
   <repo>/src/single_hand_controller
   ```

3. **Tools → Board** → **Arduino Mega or Mega 2560** → **ATmega2560 (Mega 2560)**.
4. **Tools → Port** → select the HC port.
5. **Verify** (compile only) or **Upload** (compile + flash).

To export a hex without uploading: **Sketch → Export Compiled Binary** (Arduino IDE 2.x).

---

### Option B — Arduino CLI, no IDE GUI (Windows and Linux)

From the **repository root**:

```bash
arduino-cli compile \
  --fqbn arduino:avr:mega:cpu=atmega2560 \
  --output-dir Build/cli-build \
  src/single_hand_controller/single_hand_controller.ino
```

**Windows PowerShell** (same command, backticks optional):

```powershell
arduino-cli compile `
  --fqbn arduino:avr:mega:cpu=atmega2560 `
  --output-dir Build\cli-build `
  src\single_hand_controller\single_hand_controller.ino
```

Output hex:

```
Build/cli-build/single_hand_controller.ino.hex
```

---

### Where the hex file ends up (by OS and method)

| OS | Method | Hex location |
|----|--------|--------------|
| **Windows** | Arduino IDE → **Export compiled Binary** | `src\single_hand_controller\build\arduino.avr.mega\single_hand_controller.ino.hex` |
| **Windows** | Arduino CLI (`--output-dir`) | `Build\cli-build\single_hand_controller.ino.hex` |
| **Windows** | Arduino IDE cache (verbose log) | `%LOCALAPPDATA%\arduino\sketches\<hash>\single_hand_controller.ino.hex` |
| **Linux** | Arduino IDE → **Export compiled Binary** | `src/single_hand_controller/build/arduino.avr.mega/single_hand_controller.ino.hex` |
| **Linux** | Arduino CLI (`--output-dir`) | `Build/cli-build/single_hand_controller.ino.hex` |
| **Linux** | Arduino IDE cache | `~/.cache/arduino/sketches/<hash>/single_hand_controller.ino.hex` |
| **Linux** | `import_build.sh` | `Build/<hash>/single_hand_controller.ino.hex` |
| **Repo** | Canonical copy (update manually) | `Build/current/single_hand_controller.ino.hex` |
| **Repo** | Legacy prebuilt (may be stale) | `Build/4B84089CB73F43CCD32C0EAD5298DF55/single_hand_controller.ino.hex` |

Use **`single_hand_controller.ino.hex`** for normal USB flashing.

**Do not use** `single_hand_controller.ino.with_bootloader.hex` unless programming via ISP / replacing the bootloader.

---

## Step 3 — Copy into `Build/` (optional)

Skip if you flash directly from `Build/cli-build/` or only need on-device validation (see **Validate firmware** below).

Prefer **`Build/current/`** as the canonical repo copy (see **Update `Build/` with a new compile** in the validation section).

| OS | Action |
|----|--------|
| **Linux** | `sh import_build.sh` (from repo root), or copy exported hex into `Build/current/` |
| **Windows** | Copy exported hex into `Build\current\` (see validation section) |

---

## Step 4 — Flash with avrdude (no Arduino IDE GUI)

Run from the **repository root**. Replace the port with your HC port.

### Linux

```bash
avrdude -v -p m2560 -c wiring -P /dev/ttyACM0 -b 115200 -D \
  -U flash:w:"Build/cli-build/single_hand_controller.ino.hex":i
```

Or use the repo script (default port `/dev/ttyACM0`, path under `Build/4B84089…`):

```bash
sh flash_code.sh
# Custom port (if script args match your version):
# sh flash_code.sh /dev/ttyUSB0
```

### Windows (PowerShell)

Set variables (adjust paths and `COM` port):

```powershell
$port    = "COM3"
$hex     = "Build\cli-build\single_hand_controller.ino.hex"
$avrdude = "$env:LOCALAPPDATA\Arduino15\packages\arduino\tools\avrdude\8.0.0-arduino1\bin\avrdude.exe"
$conf    = "$env:LOCALAPPDATA\Arduino15\packages\arduino\tools\avrdude\8.0.0-arduino1\etc\avrdude.conf"

& $avrdude -C $conf -v -p m2560 -c wiring -P $port -b 115200 -D -U "flash:w:$hex:i"
```

Prebuilt hex in the repo instead:

```powershell
$hex = "Build\4B84089CB73F43CCD32C0EAD5298DF55\single_hand_controller.ino.hex"
```

List port:

```powershell
arduino-cli board list
```

### avrdude flags (reference)

| Flag | Meaning |
|------|---------|
| `-p m2560` | ATmega2560 |
| `-c wiring` | Mega USB bootloader |
| `-P <port>` | `COM3` (Windows) or `/dev/ttyACM0` (Linux) |
| `-b 115200` | Upload baud rate |
| `-D` | Normal upload (no full-chip erase) |
| `-U flash:w:…:i` | Write Intel HEX to flash |

On success the Mega resets automatically.

---

## Validate firmware (checksum / flash verify)

This is the HC equivalent of checking a Docker image digest: confirm that **what is on the Mega** matches **the hex file you expect**.

### Important — why upload and verify can disagree

| Action | Which hex is used |
|--------|-------------------|
| **Arduino IDE → Upload** | Compiles `.ino` → flashes the **new** hex from Arduino’s build folder |
| **Old `Build/4B84089…/…hex` in repo** | A **saved snapshot** — not updated automatically on Upload |

If you Upload from the IDE but verify against an old `Build\…` file, **mismatch is expected** even when upload succeeded.

**Rule:** Always verify against the hex you **actually built or flashed** (export path, `Build/cli-build/`, or `Build/current/` after you update it).

Use **`single_hand_controller.ino.hex`** only (not `with_bootloader.hex` for normal USB).

**Before verify:** close Arduino **Serial Monitor** and anything else on the HC port.

---

### Where to find the actual hex (Arduino IDE)

After **Verify** or **Upload**:

1. **Sketch → Export compiled Binary** (Arduino IDE 2.x).
2. Open the export folder:

   ```
   <repo>/src/single_hand_controller/build/arduino.avr.mega/single_hand_controller.ino.hex
   ```

   Windows example:

   ```
   C:\Users\<you>\Desktop\HC\scout-td0-HC\src\single_hand_controller\build\arduino.avr.mega\single_hand_controller.ino.hex
   ```

3. **Optional — see path in the log:** **File → Preferences** → enable **Show verbose output during: compilation** → Verify again → search Output for `single_hand_controller.ino.hex`.

That exported file is the **ground truth** for IDE builds.

---

### Update `Build/` with a new compile (step by step)

Do this after each release build so `Build/` matches what you flash in the field.

#### Windows (PowerShell)

```powershell
cd C:\Users\<you>\Desktop\HC\scout-td0-HC

# 1) Compile in Arduino IDE (Verify or Upload), then:
#    Sketch → Export compiled Binary

# 2) Copy exported hex into canonical repo folder
$src = "src\single_hand_controller\build\arduino.avr.mega\single_hand_controller.ino.hex"
$dst = "Build\current\single_hand_controller.ino.hex"
New-Item -ItemType Directory -Force -Path "Build\current" | Out-Null
Copy-Item $src -Destination $dst -Force

# 3) Record digest for release notes / CI (optional)
Get-FileHash $dst -Algorithm SHA256
```

If you built with **Arduino CLI** instead:

```powershell
Copy-Item "Build\cli-build\single_hand_controller.ino.hex" -Destination "Build\current\single_hand_controller.ino.hex" -Force
Get-FileHash "Build\current\single_hand_controller.ino.hex" -Algorithm SHA256
```

#### Linux

```bash
cd scout-td0-HC

# After IDE Export compiled Binary:
mkdir -p Build/current
cp src/single_hand_controller/build/arduino.avr.mega/single_hand_controller.ino.hex \
   Build/current/single_hand_controller.ino.hex

sha256sum Build/current/single_hand_controller.ino.hex

# Or copy from Arduino cache via helper script:
sh import_build.sh
# then copy/move the hash folder contents to Build/current/ if desired
```

Commit `Build/current/single_hand_controller.ino.hex` when your team tracks binaries in git.

---

### Validate after **Arduino IDE Upload**

IDE Upload already verifies against its own build during upload. To **double-check** manually:

#### Windows (PowerShell) — works with avrdude 8 on Windows

`avrdude` splits `-U` arguments on `:`. Paths like `C:\Users\…` break the command. Copy the reference hex to a **short temp folder** and use a **simple filename**:

```powershell
# 1) Prep reference = TODAY'S export (NOT old Build\4B84089… unless you know it's current)
$tmp = "$env:TEMP\hc_verify"
New-Item -ItemType Directory -Force -Path $tmp | Out-Null
Copy-Item "C:\Users\<you>\Desktop\HC\scout-td0-HC\src\single_hand_controller\build\arduino.avr.mega\single_hand_controller.ino.hex" `
  -Destination "$tmp\hc_ref.hex" -Force

# 2) avrdude from Arduino IDE install
$avrdude = "$env:LOCALAPPDATA\Arduino15\packages\arduino\tools\avrdude\8.0.0-arduino1\bin\avrdude.exe"
$conf    = "$env:LOCALAPPDATA\Arduino15\packages\arduino\tools\avrdude\8.0.0-arduino1\etc\avrdude.conf"

# 3) Run FROM temp folder — simple filename only
cd $tmp
& $avrdude -C $conf -p m2560 -c wiring -P COM4 -b 115200 -D -U "flash:v:hc_ref.hex:i"
```

Replace `COM4` with your port (**Tools → Port** in IDE).

**Success:** ends with `Avrdude done` and **no** `verification mismatch`.

**Failure:** `verification mismatch` → HC flash ≠ `hc_ref.hex` (wrong reference file or flash failed).

To verify against updated repo copy instead:

```powershell
Copy-Item "C:\Users\<you>\Desktop\HC\scout-td0-HC\Build\current\single_hand_controller.ino.hex" -Destination "$tmp\hc_ref.hex" -Force
```

#### Linux

```bash
# Reference hex (exported or Build/current)
REF=Build/current/single_hand_controller.ino.hex

avrdude -v -p m2560 -c wiring -P /dev/ttyACM0 -b 115200 -D \
  -U flash:v:"$REF":i
```

Or use the repo script (legacy path under `Build/4B84089…`):

```bash
sh check_version_change.sh /dev/ttyACM0
```

---

### Validate after **flash without IDE** (`avrdude` only)

Use the **same hex file you flashed** as the reference.

#### Windows

```powershell
# After flashing Build\cli-build\ or Build\current\ ...
$tmp = "$env:TEMP\hc_verify"
New-Item -ItemType Directory -Force -Path $tmp | Out-Null
Copy-Item "C:\Users\<you>\Desktop\HC\scout-td0-HC\Build\current\single_hand_controller.ino.hex" -Destination "$tmp\hc_ref.hex" -Force

$avrdude = "$env:LOCALAPPDATA\Arduino15\packages\arduino\tools\avrdude\8.0.0-arduino1\bin\avrdude.exe"
$conf    = "$env:LOCALAPPDATA\Arduino15\packages\arduino\tools\avrdude\8.0.0-arduino1\etc\avrdude.conf"

cd $tmp
& $avrdude -C $conf -p m2560 -c wiring -P COM4 -b 115200 -D -U "flash:v:hc_ref.hex:i"
```

#### Linux

```bash
# After: avrdude ... -U flash:w:Build/current/single_hand_controller.ino.hex:i
avrdude -v -p m2560 -c wiring -P /dev/ttyACM0 -b 115200 -D \
  -U flash:v:Build/current/single_hand_controller.ino.hex:i
```

---

### Optional — SHA256 of the hex **file** (artifact digest)

This checks that two **files on disk** are identical (repo vs export). It does **not** read the Mega by itself.

**Windows:**

```powershell
Get-FileHash "Build\current\single_hand_controller.ino.hex" -Algorithm SHA256
Get-FileHash "src\single_hand_controller\build\arduino.avr.mega\single_hand_controller.ino.hex" -Algorithm SHA256
```

**Linux:**

```bash
sha256sum Build/current/single_hand_controller.ino.hex
sha256sum src/single_hand_controller/build/arduino.avr.mega/single_hand_controller.ino.hex
```

Same SHA256 → same build artifact. Then use **flash verify** (`flash:v`) above to confirm the HC was flashed with it.

---

### Validation troubleshooting

| Symptom | Likely cause | Fix |
|---------|----------------|-----|
| `cannot determine file format for ,` (Windows) | `C:\` in `-U flash:v:C:\…` breaks parsing | Use `%TEMP%\hc_verify\hc_ref.hex` workflow above |
| Mismatch after IDE Upload | Verified against **old** `Build\4B84089…` | Use **exported** hex or `Build\current\` |
| `can't open device COMx` | Wrong port or port in use | Match IDE **Tools → Port**; close Serial Monitor |
| Upload OK, manual verify fails | Reference copy is stale | Re-export → copy to `hc_ref.hex` → verify again |
| `avrdude` not found (Windows) | Arduino IDE / CLI not installed | Use `%LOCALAPPDATA%\Arduino15\…\avrdude.exe` |

---

## Quick reference

| Goal | Windows | Linux |
|------|---------|-------|
| **GUI: build + flash** | Arduino IDE → Upload | Arduino IDE → Upload |
| **CLI: build** | `arduino-cli compile … --output-dir Build\cli-build` | Same with `/` paths |
| **CLI: flash** | PowerShell + `avrdude.exe` from Arduino15 | `avrdude` or `sh flash_code.sh` |
| **Copy IDE build to `Build/`** | Export → `Build\current\` | Export → `Build/current/` |
| **Validate on HC** | `avrdude flash:v` via `%TEMP%\hc_verify` | `avrdude flash:v` or `check_version_change.sh` |

---

## Troubleshooting

| Problem | What to check |
|---------|----------------|
| `can't open device` / `ser_open()` | Wrong port; close Serial Monitor / Atlas |
| `programmer is not responding` | USB cable, port, or try another USB socket |
| `avrdude` not found (Windows) | Install Arduino CLI + `arduino-cli core install arduino:avr` |
| `avrdude` not found (Linux) | `sudo apt install avrdude` or use Arduino CLI tools |
| Wrong / missing hex | Rebuild; use `.ino.hex` not `with_bootloader` |
| Repo `arduino/tools/avrdude` fails on Windows | Expected — use `%LOCALAPPDATA%\Arduino15\…\avrdude.exe` |
| Verify mismatch after Upload | Compared wrong reference hex | See **Validate firmware** — use exported hex or `Build/current/` |

---

## Further documentation

- [src/error_handling.md](src/error_handling.md) — on-screen error codes
- [src/readme.md](src/readme.md) — compile modes (release, debug, radio config), MAVLink, project structure
- [docs/HC_LINK_USB_VS_RADIO.md](docs/HC_LINK_USB_VS_RADIO.md) — USB lab link vs production UHF radio
