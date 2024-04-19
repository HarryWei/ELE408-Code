#!/bin/bash

echo -n "Enter a num: "

read num

if [ "$num" -lt 10 ];
then
	if [ "$num" -gt 1 ];
	then
		echo "$num*$num=$(($num*$num))"
	else
		echo "Wrong!"
	fi
else
	echo "Incorrect!"
fi
