SRCS = circularLinkedList.c

OBJS = ${SRCS:.c=.o}

CC = gcc
#CFLAGS = -Wall -Werror -Wextra -I.
RM = rm -f

all: ${OBJS}
	${CC} Cserv.c -o Cserv ${OBJS}
	${CC} Dcli.c -o Dcli ${OBJS}
clean:
	${RM} ${OBJS}
fclean: clean
	${RM} Cserv Dcli
re: fclean all

.PHONY: all clean fclean re
