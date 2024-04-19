#!/bin/bash


usernames=`cat ./cs288-102.txt`

#for username in $usernames
#do
#	echo $username
#done

for username in $usernames
do
	sudo useradd -m -s /bin/bash -p $(perl -e 'print crypt($ARGV[0], "password")' "$username") $username
done
