#!/bin/bash

set -x

for x in paper pencil pen
do
	echo "The value of variable x is: $x"
	sleep 1
done


for x in "paper pencil pen"
do
	echo "The value of variable x is: $x"
	sleep 1
done
