NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRC = push_swap.c moves_a.c moves_b.c moves_a_b.c big_sort.c utils.c algorithm.c ysf.c
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
