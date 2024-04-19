#!/bin/bash

Suites="Clubs Diamonds Hearts Spades"
Denominations="2 3 4 5 6 7 8 9 10 Jack Queen King Ace"

suite=($Suites)
denomination=($Denominations)

num_suites=${#suite[*]}
num_denominations=${#denomination[*]}

echo $num_suites
echo $num_denominations

flag=0

for((i=0;i<$num_suites;i++))
do
	#echo ${suite[$i]}
	if [ "Tom" == "${suite[$i]}" ]; then
		echo "Tom is here!"
	else
		echo "Tom is not here!"
	fi
done

echo ${suite[*]}
echo ${suite[@]}
