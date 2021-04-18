# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 17:48:57 by user42            #+#    #+#              #
#    Updated: 2021/04/18 20:06:41 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ---------- Executables
NAME_C=checker
NAME_PS=push_swap
LIBFT=libft/libft.a

# ---------- Commands
CC=gcc
FLAGS=-Wall -Wextra -Werror

# ---------- SRCS, OBJS and INC
INC=-I includes
SRC_PATH=src
SRCS= builtins.c reverse_rotate.c errors.c rotate.c print_lst.c exec_cmd.c push.c swap.c display_stacks.c elaborate_utils.c
SRC_C= $(addprefix $(SRC_PATH)/,$(SRCS)) $(SRC_PATH)/checker.c
SRC_PS= $(addprefix $(SRC_PATH)/,$(SRCS)) $(SRC_PATH)/push_swap.c
OBJ_C=$(SRCS:.c=.o) checker.o
OBJ_PS=$(SRCS:.c=.o) push_swap.o


# ---------- Rules

all: $(NAME_C) $(NAME_PS)
	@printf "Checker compiled\n"
	@printf "Push_swap compiled\n"
	@mkdir obj
	@mv *.o obj

$(NAME_C): libft_compile
	@printf "Compiling $@\n"
	@$(CC) $(FLAGS) -c $(SRC_C) $(INC) -L $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_C) $(LIBFT) -o ${NAME_C}

$(NAME_PS): libft_compile
	@printf "Compiling $@\n"
	@$(CC) $(FLAGS) -c $(SRC_PS) $(INC) -L $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_PS) $(LIBFT) -o ${NAME_PS}

libft_compile:
	@make fclean bonus -C libft/ --silent

clean:
	@make clean -C libft/ --silent
	@rm -rf obj *.gch
	@printf "Object files removed\n"

fclean:	clean
	@make fclean -C libft/ --silent
	@rm -f $(NAME_C) $(NAME_PS)
	@printf "Executable files removed\n"

re: fclean all


# ---------- 
