#!/bin/bash

# Variables
FILE_PATH=./bin/push_swap

# Colors
C_RED='\033[0;31m'
C_YEL='\033[0;33m'
C_GRN='\033[0;32m'
C_WHT='\033[0;37m'


if [ -z "$1" ]; then
	printf "Usage ./tester.sh _SIZE_ _TESTS_";
	exit 1
else
	SIZE=$1
fi

if [ -z "$2" ]; then
	COUNT=50
else
	COUNT=$2
fi

# Funtions
function case5 () {
	if [ $1 -le 8 ]; then
		printf "$C_GRN";
	elif [ $1 -le 12 ]; then
		printf "$C_YEL";
	else
		printf "$C_RED";
	fi
	printf "$N\n";
	printf "$C_WHT"
}

# Funtions
function case100 () {
	if [ $1 -le 700 ]; then
		printf "$C_GRN";
	elif [ $1 -le 900 ]; then
		printf "$C_YEL";
	else
		printf "$C_RED";
	fi
	printf "$N\n";
	printf "$C_WHT"
}

# Code
if [ -f $FILE_PATH ]; then
	for i in `seq 1 $COUNT`
	do
		N=`expr $(./bin/push_swap $(ruby -e "puts (-10000...10000).to_a.shuffle.join(' ')" | tr ' ' '\n' | head -n $SIZE | tr '\n' ' ') | wc -l)`
		TOTAL=$(( $TOTAL + $N ))
		if [ $COUNT -le 5 ]; then
			case5 $N;
		elif [ $COUNT -le 100 ]; then
			case100 $N;
		fi
	done
else
	printf "Missing file";
	exit 1
fi

printf "\t$(( $TOTAL / $COUNT ))\n"