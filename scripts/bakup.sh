#!/bin/bash
if [ $# -ne 2 ];
then
	echo -e "Usage: ./bakup.sh src_dir dst_dir"
	exit
fi

if [ -d $1 ];
then
	if [ -d $2 ];
	then
		#cp $1 $2/
		cp -r $1 $2
	else
		echo -e "Destination dir does not exist!"
	fi
else
	echo -e "Source dir does not exist!"
fi

