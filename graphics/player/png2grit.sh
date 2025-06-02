#!/bin/bash

for file in *.png; do
    name="${file%.png}"
    echo "-g -gu8 -gB8 -gT 000000" > "$name.grit"
done
