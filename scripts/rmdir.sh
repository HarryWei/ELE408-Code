#!/bin/bash 

echo "create a dir"
mkdir trash
echo "xxx"
cp -rf ./* ./trash
rm -rf trash
