HDR			= push_swap.h checker_bonus.h
NAME		= push_swap
SRC			= push_swap.c count_rotate.c instr_push.c instr_reverse_rotate.c instr_rotate.c instr_swap.c make_stack_a.c mid_algo.c sort_morethen3.c utils.c utils2.c
OBJ			= $(SRC:.c=.o)
NAME_B		= checker
SRC_B		= checker_bonus.c input_parser.c ops_swap_bonus.c ops_rot_bonus.c ops_rr_bonus.c ops_push_bonus.c utils.c
OBJ_B		= $(SRC_B:.c=.o)
LIB_SRC		= ./libft/
LIB_NAME	= libft.a

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -I. -I$(LIB_SRC) -c $< -o $@

$(NAME): $(OBJ) $(LIB_SRC)$(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_SRC)$(LIB_NAME) -o $(NAME)

$(NAME_B): $(OBJ_B) $(LIB_SRC)$(LIB_NAME)
	$(CC) $(CFLAGS) $(OBJ_B) $(LIB_SRC)$(LIB_NAME) -o $(NAME_B)

$(LIB_SRC)$(LIB_NAME) : libft ;

libft :
	make -C $(LIB_SRC)

bonus: $(NAME_B)

clean:
	rm -f $(OBJ) $(OBJ_B)
	make clean -C $(LIB_SRC)

fclean: clean
	rm -f $(NAME)
	rm -f checker
	make fclean -C $(LIB_SRC)

re: fclean all

.PHONY : all libft clean fclean re
