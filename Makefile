#SRCS
SRCS = srcs/push_swap.c srcs/sort_small_stack.c srcs/sort_stack.c srcs/operations.c srcs/operations2.c srcs/parse.c srcs/ft_puterr.c srcs/sort_int_tab.c srcs/stack.c srcs/stack2.c srcs/stack3.c srcs/apply_move.c srcs/sort_stack_helpers.c srcs/sort_stack_helpers_a.c

SRCS_BONUS = srcs/checker_bonus.c srcs/operations.c srcs/operations2.c srcs/parse.c srcs/stack.c srcs/stack2.c srcs/ft_puterr.c

#LIBRARY
LIBFT = libft/libft.a
GNL = gnl/gnl.a

#OBJS
OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

#NAME
NAME = push_swap

NAME_BONUS = checker

#HEADERS
HEADERS = includes/stack.h includes/parse.h includes/push_swap.h

#FLAGS
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	@echo "Compiling mandatory ..."
	@cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT) : libft/libft.h
	@make -C libft/
	
$(GNL) : gnl/get_next_line.h
	@make -C gnl/

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS) $(LIBFT) $(GNL)
	@echo "Compiling bonus ..."
	@cc $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBFT) $(GNL)

%.o : %.c $(HEADERS)
	@cc $(CFLAGS) -c $< -o $@

clean :
	@echo "Deleting object files ..."
	@make clean -C libft/
	@make clean -C gnl/
	@rm -rf $(OBJS_BONUS) $(OBJS)

fclean :
	@echo "Deleting all ..."
	@make fclean -C libft/
	@make fclean -C gnl/
	@rm -rf $(NAME_BONUS) $(OBJS_BONUS) $(OBJS) $(NAME)

re : fclean all

.PHONY : fclean clean