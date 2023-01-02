NAME		=	push_swap

SRCS		=	main.c operations.c sort.c stack.c helpers.c checks.c

OBJS		=	${SRCS:.c=.o}

COMP = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(COMP) $(CFLAGS) -c $< -o ${<:.c=.o} -I includes

${NAME}: 
	$(COMP) $(CFLAGS) $(SRCS) -o $(NAME)

all:	${NAME}

clean:
	rm -f ${OBJS} 

fclean: clean
	rm -f ${NAME}

re: 	fclean all
