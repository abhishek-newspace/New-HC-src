# Switching HC link: USB (dev) vs UHF radio (production)

**Author:** Abhishek  
**Updated:** 15 Jul 2026  

**Only file to edit:** [`src/single_hand_controller/include/definitions.h`](../src/single_hand_controller/include/definitions.h)

Then: Arduino **Verify → Upload**.

---

## Production — UHF radio

In `definitions.h`:

```cpp
#define RELEASE              // uncomment this
// #define HC_LINK_OVER_USB  // comment this out (or delete the define)
```

| Path | Port |
|------|------|
| HC Mega → RFD radio | **Serial3** (pins 14 TX / 15 RX) @ 115200 |
| RFD → Scout radio → Atlas | RF (UHF) |

Serial Monitor on USB is free for optional debug (if you temporarily comment `RELEASE` and leave `HC_LINK_OVER_USB` off).

---

## Development — USB only (no radio on rig)

In `definitions.h`:

```cpp
// #define RELEASE           // keep commented
#define HC_LINK_OVER_USB    // uncomment / keep this
```

| Path | Port |
|------|------|
| HC Mega → Atlas (or USB bridge) | **USB Serial** (same COM as upload) @ 115200 |

Rules:
1. **Close Serial Monitor** — Atlas must own the COM port.  
2. Do not enable `_DEBUG_` / `PRINT_BYTES` in USB mode (they corrupt MAVLink).  
3. Error 5 (local radio) is skipped in this mode.

---

## Quick reference

| Goal | `RELEASE` | `HC_LINK_OVER_USB` |
|------|-----------|--------------------|
| Production UHF | **ON** | **OFF** |
| Dev USB ↔ Atlas | **OFF** | **ON** |
| Dev + real radio + Serial Monitor debug | **OFF** | **OFF** (+ `_DEBUG_` allowed) |

No other files need changing for the switch — `RADIO_PORT`, Error 5 skip, and `connectRadio()` already follow `HC_LINK_OVER_USB` / `RADIO_SIMULATION_TESTING`.
