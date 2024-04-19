#!/bin/bash

echo -n "Enter your login: "

read name

if [ "$name" = "$USER" ];
then
	echo "Welcome!"
else
	echo "Incorrect!"
fi
