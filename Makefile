# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 17:48:57 by user42            #+#    #+#              #
#    Updated: 2021/05/09 23:17:29 by user42           ###   ########.fr        #
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

SRC_DIR=src/
SRC_C= checker.c builtins.c reverse_rotate.c errors.c rotate.c print_lst.c exec_cmd.c push.c swap.c display_stacks.c elaborate_utils.c elaborate_utils_2.c elab_small.c elab_big.c elab_big_utils.c
SRC_PS= push_swap.c builtins.c reverse_rotate.c errors.c rotate.c print_lst.c exec_cmd.c push.c swap.c display_stacks.c elaborate_utils.c elaborate_utils_2.c elab_small.c elab_big.c elab_big_utils.c

OBJ_DIR=obj/
OBJ_C=$(addprefix $(OBJ_DIR),$(SRC_C:.c=.o))
OBJ_PS=$(addprefix $(OBJ_DIR),$(SRC_PS:.c=.o))

# ---------- Colors
BLACK:="\033[1;30m"
RED:="\033[1;31m"
GREEN:="\033[1;32m"
PURPLE:="\033[1;35m"
CYAN:="\033[1;36m"
WHITE:="\033[1;37m"
EOC:="\033[0;0m"

# ---------- Rules

all: $(NAME_C) $(NAME_PS)
	@printf $(GREEN)" -------------- Checker compiled   ----------------\n"
	@printf " -------------- Push_swap compiled ----------------\n"$(EOC)

$(NAME_C): $(LIBFT) $(OBJ) $(OBJ_C)
	@$(CC) $(FLAGS) $(OBJ_C) $(LIBFT) -o $(NAME_C)

$(NAME_PS): $(LIBFT) $(OBJ) $(OBJ_PS)
	@$(CC) $(FLAGS) $(OBJ_PS) $(LIBFT) -o $(NAME_PS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@printf $(CYAN)" -------------- Compiling $@ ---------------\n"$(EOC)
	@$(CC) $(FLAGS) -o $@ -c $< $(INC) -L $(LIBFT)

$(LIBFT):
	@echo $(PURPLE) "-------------- Compiling libft -------------------" $(EOC)
	@make fclean bonus -C libft/ --silent

clean:
	@make clean -C libft/ --silent
	@rm -rf *.gch obj/*
	@printf $(RED)" -------------- Object files removed --------------\n"$(EOC)

fclean:	clean
	@make fclean -C libft/ --silent
	@rm -f $(NAME_C) $(NAME_PS)
	@printf $(RED)" -------------- Executable files removed ----------\n"$(EOC)

re: fclean all

# ---------- 
