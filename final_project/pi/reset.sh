#!/bin/bash

echo "" > ~/data.dat
echo "clear ~/data.dat"

echo "~/index = 1"
echo "1" > ~/index

echo "remove ~/backup/*.dat"
rm ~/backup/*.dat 2>/dev/null

echo "remove ~/eoe-plot/page*"
rm ~/eoe-plot/page* 2>/dev/null

echo "remove ~/eoe-plot/plot*"
rm ~/eoe-plot/plot* 2>/dev/null

echo "Plotage reseted!"
