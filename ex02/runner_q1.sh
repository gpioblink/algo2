#!/bin/bash

OUTPUT_NAME=${1:-data}
N=${2:-5}
echo "0 0" > $OUTPUT_NAME.dat

for i in 50000 100000 150000 200000 250000 300000
do

sum=0

for j in `seq $N`
do

result=`./a.out $i`
time=`echo $result | awk '{print $6}'`
sum=`echo "scale=3; $time + $sum" | bc`
echo $result

done

ave=`echo "scale=3; $sum / $N" | bc`
echo "***" ave for $i is $ave "***"
echo $i $ave >> $OUTPUT_NAME.dat
done

echo "set style line 1 linecolor rgb '#0060ad' linetype 1 linewidth 2 pointtype 7 pointsize 1.5" > tmp.plt
echo "set terminal png" >> tmp.plt
echo "set output '$OUTPUT_NAME.png'" >> tmp.plt

echo "set grid" >> tmp.plt
echo "set xlabel 'data size'" >> tmp.plt
echo "set ylabel 'elapsed time [msec]'" >> tmp.plt
echo "plot '$OUTPUT_NAME.dat' with linespoints linestyle 1" >> tmp.plt

gnuplot tmp.plt
# rm -f tmp.plt