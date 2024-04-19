#!/bin/bash


usernames=`cat ./cs288-101.txt`

#for username in $usernames
#do
#	echo $username
#done

for username in $usernames
do
	sudo userdel $username
	sudo rm -rf /home/$username
done
