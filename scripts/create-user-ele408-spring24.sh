#!/bin/bash


#usernames=`cat ./ele408-spring2024.txt`

#for username in $usernames
#do
#	echo $username
#done


#echo $usernames

for username in uri100641404 uri100664789 uri100670897 uri100716063 uri100718184 uri100710750 uri100766639 uri100641260 uri100717878 uri100689651 uri100728517 uri100716296 uri100671061 uri100759260 uri100724202 uri100690323 uri100714080 uri100716185 uri100710198 uri100726328 uri100717955 uri100825404 uri100605641 uri100703177 uri100609395
do
	#echo $username
	sudo useradd -m -s /bin/bash -p $(perl -e 'print crypt($ARGV[0], "password")' "$username") $username
done
