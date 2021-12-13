#!/bin/bash

# little cat or coffee ascii art
#                                 /|
#                                ///
#                               / /
#                              ||\\
#                              /   \
#                              |   |
#                        r     \   \     r^-
#                        |\---- |   |---/|
#                        /      |   | |  \
#           - - - - -   (      /   /      ) - - - - - - -
#             - - - - - \      |   |      / - - - - -
#                  __-----^----|   |----^--#----+
#                 H            |   |             #
#               /             /     \             \
#             {          /       *                 \
#             -/       /                 9\         \-
#             {        |                   |        }
#             {        }                   {        }
#             #   ^    }                   {        }
#             {        }-\__---\____-----#-{        }
#            {^_^} v{-_-}                 {*_*} v(0_0}


VALGRIND=1
which valgrind 1> /dev/null 2> /dev/null
if [ $? -ne 0 ]; then
	VALGRIND=0
fi

OKAY="\e[92m\xE2\x9C\x94"
NONO="\xE2\x9D\x8C"

RED="\e[31m"
GREEN="\e[32m"
CYAN="\e[36m"
BLUE="\e[34m"
MAGENTA="\e[35m"
RESET="\e[0m"

STD_VECTOR="std::vector<int>"
FT_VECTOR="ft::vector<int>"

_loop_in_category() {
	for filename in $1*.cpp; do
		printf "$CYAN%-45s" $filename
		printf "| "
		clang++ -g3 -Wall -Werror -Wextra -std=c++98 -D CONTAINER="$STD_VECTOR" $filename 2> $filename".compile_error"
		if [ $? -ne 0 ]; then
			echo -e $RED"Compiler error"
			continue
		fi
		./a.out > "$filename.actual_output"
		rm -rf a.out
		
		echo -ne $BLUE"Compile"$RESET" : "
		clang++ -g3 -Wall -Werror -Wextra -std=c++98 -D CONTAINER="$FT_VECTOR" $filename 2> $filename".compile_error"
		if [ $? -ne 0 ]; then
			echo -e $RED$NONO$CYAN
			rm -rf "$filename.actual_output"
			continue
		else
			echo -ne $GREEN$OKAY$CYAN"  | "
			rm -rf $filename".compile_error"
		fi
		
		echo -ne $BLUE"Leaks"$RESET" : "
		if [ $VALGRIND -eq 1 ]; then
			valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all ./a.out 1> $filename".your_output" 2> $filename".leaks_error"
			if [ $? -ne 0 ]; then
				echo -ne $RED$NONO$CYAN" | "
			else
				echo -ne $GREEN$OKAY$CYAN"  | "
				rm -rf $filename".leaks_error"
			fi
		else
			./a.out > $filename".your_output"
		fi
		rm -rf a.out
		
		echo -ne $BLUE"Diff"$RESET" : "
		diff $filename".your_output" $filename".actual_output" 1> /dev/null 2> /dev/null
		if [ $? -ne 0 ]; then
			echo -ne $RED$NONO$CYAN
		else
			echo -ne $GREEN$OKAY$CYAN" "
			rm -rf $filename".your_output"
			rm -rf $filename".actual_output"
		fi
		echo
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

rm -rf */*/*.actual_output
rm -rf */*/*.your_output
rm -rf */*/*.compile_error
rm -rf */*/*.leaks_error

if [[ $# -eq 1 && $1 -eq "all" ]]; then
	_loop_all
elif [[ $# -eq 1 && -d "$1" ]]; then
	_loop_in_container "$1/"
elif [[ $# -eq 2 && -d "$1/$2" ]]; then
	_loop_in_category "$1/$2/"
else
	echo -e $CYAN"Enter one of the following :"
	echo -e $BLUE"all"$CYAN" : test every container"
	echo -e $BLUE"<container_name>"$CYAN" : test a specific container -> $BLUE bash test.sh vector"
	echo -e $BLUE"<container_name> <category_name>"$CYAN" : test a specific category of a specific container -> $BLUE bash test vector constructor"
	exit
fi


