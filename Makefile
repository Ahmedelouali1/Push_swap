NAME = push_swap
CC = gcc
RM = -rf
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c sa.c sb.c ss.c utils.c
INCLUDE = push_swap.h

OBJS = ${SRCS : .c= .o}

all : ${NAME}

clean :git 

fclean : 

re : fclean all

.PHONY : all clean fclean re
