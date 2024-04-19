#!/bin/bash

loop=y;
choice=d

case $choice in
	D | d) date ;;
	W | w) who ;;
	P | p) pwd ;;
	Q | q) loop=n ;;
	*) echo "Illegal choice." ;;
esac
