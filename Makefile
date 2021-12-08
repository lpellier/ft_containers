NAME = test

CC = clang++

CFLAGS = -g -Wall -Werror -Wextra -std=c++98

SRCS = 		./main.cpp 

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

clean : 
	$(RM) $(NAME)

re : clean all

