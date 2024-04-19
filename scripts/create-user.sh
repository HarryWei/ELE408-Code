#!/bin/bash

for username in test2 test3
do
	sudo useradd -m -s /bin/bash -p $(perl -e 'print crypt($ARGV[0], "password")' "$username") $username
done
