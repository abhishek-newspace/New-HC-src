#!/bin/sh
# Verify that the firmware currently on the Mega 2560 matches a given .hex file.
# This is the "checksum / verify" step: avrdude reads the chip and compares it to the file.
#
# Usage (run from the repository root):
#   ./check_version_change.sh                # default port /dev/ttyACM0
#   ./check_version_change.sh /dev/ttyACM0
#   ./check_version_change.sh COM5
#   ./check_version_change.sh COM5 path/to/file.hex

set -e

REPO_ROOT="$(CDPATH= cd -- "$(dirname "$0")" && pwd)"
cd "$REPO_ROOT"

PORT="${1:-/dev/ttyACM0}"
HEX="${2:-}"

if [ -z "$HEX" ]; then
  HEX="$(find ./Build -type f -name 'single_hand_controller.ino.hex' ! -name '*.with_bootloader.hex' 2>/dev/null | head -n 1)"
fi

if [ -z "$HEX" ] || [ ! -f "$HEX" ]; then
  echo "ERROR: Could not find single_hand_controller.ino.hex under ./Build/"
  exit 1
fi

echo "Verifying chip against: $HEX"
echo "Port:                   $PORT"
echo
echo "PASS  = chip contents match the .hex (avrdude reports verification OK)"
echo "FAIL  = chip contents differ (wrong build flashed, or flash incomplete)"
echo

# flash:v = verify only (does not write). Exit code non-zero on mismatch.
avrdude -v -p m2560 -c wiring -P "$PORT" -b 115200 -D -U "flash:v:${HEX}:i"

echo
echo "Verification completed successfully — on-chip flash matches the .hex file."
