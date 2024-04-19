#!/bin/bash
#####!/bin/bash -x

#FIXME: cannot work with ./

function traverse(){
  if [ -d "${entries[0]}" ] ; then
    for file in "${entries[0]}"/*; do
       entries=("${entries[*]}" "${file}")
	   #echo "entries are: ${entries[@]}"
       echo $file
    done
  fi
  echo "entries are: ${entries[*]}"
  echo "entries:0 are: ${entries[*]:0}"
  echo "entries:1 are: ${entries[*]:1}"
  echo "entries:2 are: ${entries[*]:2}"
  entries=(${entries[*]:1})
  #echo "entries are: ${entries[@]}"
  #echo "_entries are: ${_entries[@]}"
  if [ ${#entries[*]} -ne 0 ] ; then
     traverse ${entries[0]}
  fi
}

IFS=""
entries[0]="$1"
traverse "$1"
