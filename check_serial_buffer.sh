#! /bin/sh
port='/dev/ttyACM0'
if [ "$#" -lt 2 ]; then
cat $port
else
cat $1
fi
