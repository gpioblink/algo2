#!/bin/bash -x

N=5
echo "# number time" > data.dat

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
echo "***" ave for $i is $sum "***"
echo $i $ave >> data.dat
done