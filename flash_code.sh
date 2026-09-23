#!/bin/sh
# Flash Helios HC firmware (.hex) to Arduino Mega 2560 via USB.
#
# Usage (run from the repository root):
#   ./flash_code.sh                  # default port /dev/ttyACM0 (Linux)
#   ./flash_code.sh /dev/ttyACM0     # Linux — explicit port
#   ./flash_code.sh COM5             # Windows (Git Bash / WSL — COM port as shown in Device Manager)
#
# Optional 2nd argument: path to .hex (defaults to newest under Build/)

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
  echo "Place a release .hex under Build/<folder>/ or pass the path as the 2nd argument."
  exit 1
fi

echo "Flashing: $HEX"
echo "Port:     $PORT"
echo

avrdude -v -p m2560 -c wiring -P "$PORT" -b 115200 -D -U "flash:w:${HEX}:i"

echo
echo "Flash finished. Run ./check_version_change.sh $PORT to verify the chip matches this .hex."
