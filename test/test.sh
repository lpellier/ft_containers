#!/bin/bash

OKAY="\e[92m\xE2\x9C\x94"
NONO="\xE2\x9D\x8C"

RED="\e[31m"
GREEN="\e[32m"
CYAN="\e[36m"
RESET="\e[0m"

STD_VECTOR="const std::vector<int>"
FT_VECTOR="const ft::vector<int>"

function _compile () {
	clang++ -Wall -Werror -Wextra -std=c++98 -D CONTAINER="$1" $2 2> /dev/null
}

rm -rf */*output
for folder in */; do
	for filename in $folder*.cpp; do
		GRADE="$GREEN$OKAY"
		_compile "$STD_VECTOR" "$filename" && ./a.out > $filename".actual_output"
		_compile "$FT_VECTOR" "$filename" && ./a.out > $filename".your_output"
		if [ $? -ne 0 ]; then
			GRADE="$RED$NONO Compile error"
		fi
		diff $filename".your_output" $filename".actual_output" 1> /dev/null 2> /dev/null
		if [ $? -ne 0 ]; then
			GRADE="$RED$NONO Different output"
		fi
		echo -e "$RESET\e[36m$filename : $GRADE$RESET"
	done
done
rm -rf a.out
