#!/bin/bash

for username in jb794 nc42 se6 prg5 dg96 zfm3 ntm4 fn88 bmo23 to9 ilp3 jar269 ss588 eu27 cev9 rav32
do
	#sudo useradd -m -s /bin/bash -p $(perl -e 'print crypt($ARGV[0], "password")' "$username") $username
	sudo userdel $username
	sudo rm -rf /home/$username
done
