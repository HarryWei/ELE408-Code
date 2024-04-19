#!/bin/bash


usernames=`cat ./ele569.txt`

#for username in $usernames
#do
#	echo $username
#done

for username in $usernames
do
	sudo useradd -m -s /bin/bash -p $(perl -e 'print crypt($ARGV[0], "password")' "$username") $username
done
