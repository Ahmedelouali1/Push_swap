NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror 
SRC = push_swap.c moves_a.c moves_b.c moves_a_b.c big_sort.c utils.c utils2.c sort_five.c \
	algorithm.c	check_valid.c make_list.c sort.c
INCLUDE = push_swap.h

OBJS = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o : %.c ${INCLUDE}
	${CC} ${CFLAGS} -o $@ -c $<

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
