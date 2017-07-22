#!/bin/bash
gnuplot -p <<EOF
load '~/Desktop/plot.script'
load '~/Desktop/plot.script'
quit
EOF
eog 'Desktop/plot.jpg'
