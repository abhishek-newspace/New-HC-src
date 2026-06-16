#!/bin/sh
echo "Enter Build file location (~/.cache/arduino/sketches/:)"
read folder_location
rm -rf ./Build/*
mv ~/.cache/arduino/sketches/$folder_location ./Build
