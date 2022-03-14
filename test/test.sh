#!/bin/bash

VALGRIND=0
which valgrind 1> /dev/null 2> /dev/null
if [ $? -ne 0 ]; then
	VALGRIND=0
fi

ERRORS=0
COMPILER_ERROR=1
RES=0

OKAY="\e[92m\xE2\x9C\x94"
NONO="\xE2\x9D\x8C"

RED="\e[31m"
GREEN="\e[32m"
CYAN="\e[36m"
BLUE="\e[34m"
MAGENTA="\e[35m"
RESET="\e[0m"

STD_NAMESPACE="std"
FT_NAMESPACE="ft"

TYPE_INT="int"

_output_kitty() {
	if [ $ERRORS -eq 0 ]; then
		echo -e "$GREEN" ; cat .ascii_art/goodkitty.txt
	else 
		echo -e "$RED" ; cat .ascii_art/badkitty.txt
	fi
}

_compile() {
	let "COMPILER_ERROR=1"

	while [ $COMPILER_ERROR -eq 1 ]
	do
		if [[ $4 -eq 1 ]]; then
			clang++ -g3 -Wall -Werror -Wextra -std=c++98 -D TEST_TYPE="$1" -D NAMESPACE="$2" $3 | grep "Input/output error" &> /dev/null
			if [[ $? -ne 0 ]]; then
				return 0
			fi
		else
			clang++ -g3 -Wall -Werror -Wextra -std=c++98 -D TEST_TYPE="$1" -D NAMESPACE="$2" $3 2> $3".compile_error"
			cat $3".compile_error" | grep "Input/output error" &> /dev/null
			local res="$?"
			if [[ $res -ne "0" && -s $3".compile_error" ]]; then
				return 1
			elif [[ $res -ne "0" ]]; then
				let "COMPILER_ERROR=0"
			fi
		fi
	done
	return 0
}

_execute() {
	printf "$CYAN%-45s" $1
	folder=$(echo $1 | head -n1 | cut -d "/" -f1)
	if [ $2 -eq 1 ]; then
		echo
	else
		printf "| "
	fi
	_compile "$TYPE_INT" "$STD_NAMESPACE" "$1" "$2"
	./a.out > "$1.actual_output"

	{ time ./a.out ; } 2> time.txt 1>/dev/null
	ACT_TIME=$(tail -n +3 time.txt | grep -o '......$' | cut -c -5 | awk '{sum += $1;} END{print sum;}')

	echo -ne $BLUE"Compile"$RESET" : "
	_compile "$TYPE_INT" "$FT_NAMESPACE" "$1" "$2"
	if [ $? -ne 0 ]; then
		let "ERRORS += 1"
		if [ $2 -eq 0 ]; then
			echo -e $RED$NONO$CYAN
		fi
		rm -rf "$1.actual_output"
		return 1
	else
		if [ $2 -eq 1 ]; then
			echo -e $GREEN$OKAY$CYAN
		else
			echo -ne $GREEN$OKAY$CYAN"  | "
			rm -rf $1".compile_error"
		fi
	fi
	
	{ time ./a.out ; } 2> time.txt 1>/dev/null
	YOUR_TIME=$(tail -n +3 time.txt | grep -o '......$' | cut -c -5 | awk '{sum += $1;} END{print sum;}')
	rm -rf time.txt
	echo -ne $BLUE"Leaks"$RESET" : "
	if [ $VALGRIND -eq 1 ]; then
		if [ $2 -eq 1 ]; then
			echo
			valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./a.out 1> $1".your_output"
		else
			valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./a.out 1> $1".your_output" 2> $1".leaks_error"
		fi
		if [ $? -ne 0 ]; then
			let "ERRORS += 1"
			if [ $2 -eq 0 ]; then
				echo -ne $RED$NONO$CYAN" | "
			fi
		else
			if [ $2 -eq 0 ]; then
				echo -ne $GREEN$OKAY$CYAN"  | "
			else
				echo -e $GREEN$OKAY$CYAN
			fi
			rm -rf $1".leaks_error"
		fi
	else
		./a.out > $1".your_output"
	fi
	rm -rf a.out
	
	echo -ne $BLUE"Diff"$RESET" : "
	if [ $2 -eq 1 ]; then
		diff $1".your_output" $1".actual_output"
	else
		diff $1".your_output" $1".actual_output" 1> $1".diff" 2> /dev/null
	fi
	if [ $? -ne 0 ]; then
		let "ERRORS += 1"
		if [ $2 -eq 0 ]; then
			echo -ne $RED$NONO$CYAN" | "
		fi
	else
		echo -ne $GREEN$OKAY$CYAN
		if [ $2 -eq 0 ]; then
			echo -ne "  | "
			rm -rf $1".diff"
		else
			echo
		fi
		rm -rf $1".your_output"
		rm -rf $1".actual_output"
	fi

	echo -ne $BLUE"Time"$RESET" : "
	if (( $(echo "$YOUR_TIME > $ACT_TIME * 20" |bc -l) )); then
		let "ERRORS += 1"
		echo -ne $RED$NONO$CYAN
	else
		echo -ne $GREEN$OKAY$CYAN
	fi
	if [ $2 -eq 1 ]; then
		echo -ne " -> your time $YOUR_TIME vs actual time $ACT_TIME"
	fi
	echo
	return 0
}

_loop_in_category() {
	for filename in $1*.cpp; do
		_execute "$filename" "0"
	done
}

_loop_in_container() {
	for category in $1*/; do
		_loop_in_category "$category"
		echo
	done
}

_loop_all() {
	for container in */; do
		_loop_in_container "$container"
		echo
	done
}

bash clean.sh

if [[ $# -eq 1 && $1 == "all" ]]; then
	_loop_all
	_output_kitty
elif [[ $# -eq 1 && -f "$1" ]]; then
	_execute "$1" "1"
elif [[ $# -eq 1 && -d "$1" ]] && [[ $1 == "vector"  ||  $1 == "stack"  ||  $1 == "map" ]]; then
	_loop_in_container "$1/"
	_output_kitty
elif [[ $# -eq 1 && -d "$1" ]]; then
	_loop_in_category "$1/"
	_output_kitty
else
	echo -e $CYAN"Enter one of the following :"
	echo -e $BLUE"all"$CYAN" : test every container"
	echo -e $BLUE"path/to/container"$CYAN" : test a specific container -> $BLUE bash test.sh vector"
	echo -e $BLUE"path/to/category"$CYAN" : test a specific category of a specific container -> $BLUE bash test vector/constructor"
	echo -e $BLUE"path/to/test"$CYAN" : test a specific test of a specific category of a specific container -> $BLUE bash test vector/modifiers/insert"
	exit
fi


