#!/bin/bash
filename='N_N_1M'
n=1
while read line; do
# reading each line
echo "Line No. $n : $line"
n=$((n+1))
done  
