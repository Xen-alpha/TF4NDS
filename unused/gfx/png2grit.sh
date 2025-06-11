#!/bin/bash

for file in *.png; do
    name="${file%.png}"
    echo "-gb -gu8 -gB8 -p" > "$name.grit"
done
