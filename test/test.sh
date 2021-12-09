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
	clang++ -v -Wall -Werror -Wextra -std=c++98 -D CONTAINER="$1" $2 2> $2".compile_error" 
	./a.out > "$2$3"
	rm -rf ./a.out
}

rm -rf */*.actual_output
rm -rf */*.your_output
rm -rf */*.compile_error
for folder in */; do
	for filename in $folder*.cpp; do
		GRADE="$GREEN$OKAY"
		_compile "$STD_VECTOR" "$filename" ".actual_output"
		_compile "$FT_VECTOR" "$filename" ".your_output"
		if [ $? -ne 0 ]; then
			GRADE="$RED$NONO Compile error"
			echo -e "$RESET\e[36m$filename : $GRADE$RESET"
			continue
		fi
		diff $filename".your_output" $filename".actual_output" 1> /dev/null 2> /dev/null
		if [ $? -ne 0 ]; then
			GRADE="$RED$NONO Different output"
			echo -e "$RESET\e[36m$filename : $GRADE$RESET"
			continue
		fi
		rm -rf $filename".your_output"
		rm -rf $filename".actual_output"
		rm -rf $filename".compile_error"
		echo -e "$RESET\e[36m$filename : $GRADE$RESET"
	done
done
