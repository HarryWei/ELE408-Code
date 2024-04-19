#!/bin/bash

a=(one two three)
b=("one two" three)
c=("one two three")

echo $a[1]
echo ${a[1]}

echo ${a[*]}
echo ${a[@]}
echo ${#a[*]}
echo ${#b[*]}
echo ${#c[*]}
echo ${a[*]:1}
echo ${a[*]:0:2}
