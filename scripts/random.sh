#!/bin/bash

Suites="Clubs Diamonds Hearts Spades"

suite=("$Suites")

echo ${suite[@]}

num_suites=${#suite[*]}

echo $num_suites

#echo ${suite[(($RANDOM/$num_suites))]}
echo $(($RANDOM/num_suites))
echo ${suite[0]}
