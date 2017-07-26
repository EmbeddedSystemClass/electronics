#!/bin/bash
DA=`cut -f1 -d'	' data.dat | head -1`
TE=`cut -f1 -d'	' data.dat | tail -1`
INDEX=`cat index`
echo "Graph From... "
echo ${DA}
echo "to.. "
echo ${TE}
echo "in file... "
echo "plot${INDEX}"
gnuplot -p <<EOF
#script
set title "E.O.E data ${DA} - ${TE}"
set terminal jpeg giant size 2400, 1400
set output './eoe-plot/plot${INDEX}.jpg'
set multiplot
set key outside Left
set style line 1 linetype 1 linecolor rgb "#4169e1" linewidth 5
set style line 2 lt 1 linecolor rgb "#2e8b57" lw 5
set style line 3 lt 1 linecolor rgb "#ffd700" lw 5
set style line 4 lt 1 linecolor rgb "#ff0000" lw 5
set yrange [-20:100]
set y2range [-200:1000]
set timefmt "%d/%m %H:%M:%S"
set xdata time
set xrange ["${DA}":"${TE}"]
set format x ""
set ytics (100, 80, 60, 40, 20, 0)
set y2tics (1000, 800, 600, 400, 200, 0)
set ylabel "°C / %"
set y2label 'lux'
set grid
set size 1.0, 0.5
set origin 0.0, 0.4
set bmargin 1
plot '~/data.dat' u 1:6 title 'temperature (°C)' w l linestyle 1 axes x1y1,'~/data.dat'      u  1:5  title 'moisture (%)' w l linestyle 2 axes x1y1,'~/data.dat' u 1:4 title 'luminosity (lux)' w l linestyle 3 axes x1y2
unset title
unset y2range
unset y2label
set bmargin 0
set timefmt "%d/%m %H:%M:%S"
set xdata time
set xrange ["${DA}":"${TE}"]
set format x "%d/%m\n%H:%M:%S"
set size 1.0, 0.3
set origin 0.0, 0.1
set tmargin 0
set yrange ["0":"100"]
set format "%1.0f"
set ytics (100, 75, 50, 25, 0)
set ylabel '%'
plot '~/data.dat' u 1:7 title 'water level (%)' w i lt 3, '~/data.dat' u 1:3 title 'battery level (%)' w l linestyle 4
unset multiplot
quit
EOF
NEWINDEX=`awk -F, '{printf("%03d\n", $1 + 1)}' index`
echo "${NEWINDEX}" > index
touch 'test'
echo "Done !"
