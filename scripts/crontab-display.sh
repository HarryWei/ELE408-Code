#!/bin/bash

users=`ls /home/`

for i in $users
do
	#echo $i
	sudo crontab -r -u $i
done
