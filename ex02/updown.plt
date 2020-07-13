set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5
set style line 2 linecolor rgb '#60ad00' linetype 1 linewidth 2 pointtype 7 pointsize 1.5

set terminal png
set output 'updownheap.png'

set grid
set xlabel 'data size'
set ylabel 'elapsed time [msec]'
plot 'upheap.dat' with linespoints linestyle 1, \
  'downheap.dat' with linespoints linestyle 2
