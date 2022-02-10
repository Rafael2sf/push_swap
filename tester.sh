#!/bin/bash
# File path of executable file.
FILE_PATH=/push_swap

# File path of checker file provided by the subject.
CHKR_PATH=/checker

# Colors
C_RED='\033[0;31m'
C_YEL='\033[0;33m'
C_GRN='\033[0;32m'
C_WHT='\033[0;37m'

# If no arguments, show usage.
if [ -z "$1" ]; then
	printf "Usage:\t./tester.sh [SIZE] [TESTS]\n\t\tImportant: edit FILE_PATH && CHKR_PATH on tester.sh file.\n";
	exit 1
else
	SIZE=$1
fi
# If number of tests not provided, default to 10
if [ -z "$2" ]; then
	COUNT=10
else
	COUNT=$2
fi
if [ ! -f "$(pwd)$CHKR_PATH" ]; then
	printf "\033[0;33mWarning\033[0;37m: Missing checker file, searching at $(pwd)$CHKR_PATH.\n";
fi
# Color scheme for list of size 3
function case3 () {
	if [ $1 -le 2 ]; then
		printf "$C_GRN";
	else
		printf "$C_RED";
	fi
	printf "$N\t";
	printf "$C_WHT"
}

# Color scheme for list of size 5
function case5 () {
	if [ $1 -le 8 ]; then
		printf "$C_GRN";
	elif [ $1 -le 12 ]; then
		printf "$C_YEL";
	else
		printf "$C_RED";
	fi
	printf "$N\t";
	printf "$C_WHT"
}
# Color scheme for list of size 100
function case100 () {
	if [ $1 -le 700 ]; then
		printf "$C_GRN";
	elif [ $1 -le 900 ]; then
		printf "$C_YEL";
	else
		printf "$C_RED";
	fi
	printf "$N\t";
	printf "$C_WHT"
}

# Color scheme for list of size 500
function case500 () {
	if [ $1 -le 5500 ]; then
		printf "$C_GRN";
	elif [ $1 -le 7000 ]; then
		printf "$C_YEL";
	else
		printf "$C_RED";
	fi
	printf "$N\t";
	printf "$C_WHT"
}

if [ -f $(pwd)$FILE_PATH ]; then
	for i in `seq 1 $COUNT`
	do
		LIST=$(ruby -e "puts (1..$SIZE).to_a.shuffle.join(' ')")
		N=`expr $(.$FILE_PATH $LIST | wc -l)`
		TOTAL=$(( $TOTAL + $N ))
		if [ $SIZE -le 3 ]; then
			case5 $N;
		elif [ $SIZE -le 5 ]; then
			case5 $N;
		elif [ $SIZE -le 100 ]; then
			case100 $N;
		elif [ $SIZE -le 500 ]; then
			case500 $N;
		else
			printf "$N\t";
		fi
		if [ -f $(pwd)$CHKR_PATH ]; then
			.$FILE_PATH $LIST | .$CHKR_PATH $LIST;
		else
			printf "\n";
		fi
	done
else
	printf "\033[0;31mError\033[0;37m: Missing file, searching at $(pwd)$FILE_PATH.\n";
	exit 1
fi

printf "\nAverage: "
echo "scale=10; $TOTAL / $COUNT" | bc