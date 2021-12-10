#!/bin/bash

OKAY="\e[92m\xE2\x9C\x94"
NONO="\xE2\x9D\x8C"

RED="\e[31m"
GREEN="\e[32m"
CYAN="\e[36m"
RESET="\e[0m"

STD_VECTOR="const std::vector<int>"
FT_VECTOR="const ft::vector<int>"
GRADE="$GREEN$OKAY"

rm -rf */*.actual_output
rm -rf */*.your_output
rm -rf */*.compile_error
rm -rf */*.leaks_error
for folder in */; do
	for filename in $folder*.cpp; do
		clang++ -Wall -Werror -Wextra -std=c++98 -D CONTAINER="$STD_VECTOR" $filename 2> $filename".compile_error"
		./a.out > "$filename.actual_output"
		rm -rf a.out
		
		clang++ -Wall -Werror -Wextra -std=c++98 -D CONTAINER="$FT_VECTOR" $filename 2> $filename".compile_error"
		if [ $? -ne 0 ]; then
			GRADE="$RED$NONO Compile error"
			echo -e "$RESET\e[36m$filename : $GRADE$RESET"
			continue
		fi
		
		valgrind --error-exitcode=2 --leak-check=full --show-leak-kinds=all ./a.out 1> $filename".your_output" 2> $filename".leaks_error"
		if [ $? -ne 0 ]; then
			GRADE="$RED$NONO Leaks detected"
			echo -e "$RESET\e[36m$filename : $GRADE$RESET"
			continue
		fi
		rm -rf a.out
		
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
		GRADE="$GREEN$OKAY"
	done
done
