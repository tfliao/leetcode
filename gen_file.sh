#!/bin/bash

echo "Generate camel-style problem name as filename"
echo "Problem name: "
read TITLE
fn=
for w in $TITLE; do
    h=$(echo $w | cut -b-1)
    fn=${fn}${h^^}$(echo $w |cut -b2-)
done
if [ -z "$fn" ]; then
    echo "Failed to generate file name"
    exit 1
fi
fn=${fn}.cpp
echo "Now read solution and write to $fn, ^D to stop"
cat > $fn

