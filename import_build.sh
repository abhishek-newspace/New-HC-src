#!/bin/sh
folder_location="4B84089CB73F43CCD32C0EAD5298DF55"
if [ "$#" -eq 4 ]; then
folder_location=$3
fi
# echo "Enter Build file location (~/.cache/arduino/sketches/:)"
# read folder_location

echo "Getting Build file from ~/.cache/arduino/sketches/$folder_location "
rm -rf ./Build/*
mv ~/.cache/arduino/sketches/$folder_location ./Build
