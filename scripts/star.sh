#!/bin/bash

echo "this is dollar *"

for arg in "$*"
do
	echo $arg
	#((i=$i+1))
done
#echo $i

echo "this is dollar @"
for arg in "$@"
do
	echo $arg
	#((j=$j+1))
done

#echo $j
