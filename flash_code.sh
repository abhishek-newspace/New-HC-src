#! /bin/sh
port='/dev/ttyACM0'
if [ "$#" -lt 3 ]; then
avrdude -v -p m2560 -c wiring -P $port -b 115200 -D -U flash:w:"./Build/4B84089CB73F43CCD32C0EAD5298DF55/single_hand_controller.ino.hex":i;
else
avrdude -v -p m2560 -c wiring -P $2 -b 115200 -D -U flash:w:"./Build/4B84089CB73F43CCD32C0EAD5298DF55/single_hand_controller.ino.hex":i
fi
