#!/bin/bash

echo "we have $# parameters"
echo "script name is $0"
echo "1st para is $1"
echo "all paras are $@ or $*"

echo "We are under $PWD"

for _file in `ls`
do
	if [ -f $_file ] && [ $PWD = "/home" ];
	then
		echo "$_file is a file"
	else
		echo "error branch!"
	fi
done
