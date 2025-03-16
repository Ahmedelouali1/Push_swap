NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = push_swap.c pa.c pb.c ra.c rb.c rr.c rra.c rrb.c sa.c sb.c ss.c utils.c
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
