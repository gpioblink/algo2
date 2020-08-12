#!/bin/bash

N=${1:-5}

for i in 4 8 16 32 64 128 256 512 1024 2048
do

sum=0

for j in `seq $N`
do

result=`./a.out $i`
time=`echo $result | awk '{print $7}'`
sum=`echo "scale=6; $time + $sum" | bc`
echo $result

done

ave=`echo "scale=6; $sum / $N" | bc`
echo "***" ave for $i is $ave "***"
done

