#!/bin/bash

join1() {
    typeset IFS=,
    echo "$*"
}

join1 a b c   # => a,b,c

for arg in "$@"
do
	echo $arg
done
