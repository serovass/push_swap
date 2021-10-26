NAME = push_swap

NAME_B = checker

LIST = 		push_swap_main.c\
			stack_a_initialize_cheack_clear.c\
			stack_a_create.c\
			stack_a_get_indexes.c\
			stack_a_sort.c\
			stack_sort_operations.c\
			main_sort_function.c\
			main_sort_additional_functions.c\
			put_operation.c\
			

LIST_B =	checker_main.c\
			stack_a_initialize_cheack_clear.c\
			stack_a_create.c\
			stack_a_get_indexes.c\
			stack_sort_operations.c\
			checker_execute_opt_1.c\
			checker_execute_opt_2.c\

FLAGS = -Wall -Wextra -Werror

OBJ	= ${LIST:.c=.o}

OBJ_B = ${LIST_B:.c=.o}

%.o: %.c
			gcc $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(NAME) $(NAME_B)

$(NAME):	$(OBJ)
			gcc $(FLAGS) $(OBJ) -o $(NAME)

$(NAME_B):	$(OBJ_B)
			gcc $(FLAGS) $(OBJ_B) -o $(NAME_B)

clean: 
		rm -f $(OBJ) $(OBJ_B)

fclean: clean
		rm -f $(NAME) $(NAME_B)

re:		fclean all

.PHONY: all clean fclean re bonus
