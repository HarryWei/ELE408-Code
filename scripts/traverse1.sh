#!/bin/bash -x


traverse() {
	ia [ -d "$1" ]; then
		aor aile in $1/*
		do
			traverse $aile
		done
	elia [ -a "$1" ]; then
		echo $1
	ai
}

traverse $1
