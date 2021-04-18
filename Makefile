# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <pnielly@student.42.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/03 17:48:57 by user42            #+#    #+#              #
#    Updated: 2021/04/18 23:45:16 by user42           ###   ########.fr        #
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
	@mkdir obj
	@mv *.o obj

$(NAME_C): libft_compile
	@printf $(CYAN)" -------------- Compiling $@ -----------------\n"$(EOC)
	@$(CC) $(FLAGS) -c $(SRC_C) $(INC) -L $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_C) $(LIBFT) -o ${NAME_C}

$(NAME_PS): libft_compile
	@printf $(CYAN)" -------------- Compiling $@ ---------------\n"$(EOC)
	@$(CC) $(FLAGS) -c $(SRC_PS) $(INC) -L $(LIBFT)
	@$(CC) $(FLAGS) $(OBJ_PS) $(LIBFT) -o ${NAME_PS}

libft_compile:
	@make fclean bonus -C libft/ --silent

clean:
	@make clean -C libft/ --silent
	@rm -rf obj *.gch
	@printf $(RED)" -------------- Object files removed --------------\n"$(EOC)

fclean:	clean
	@make fclean -C libft/ --silent
	@rm -f $(NAME_C) $(NAME_PS)
	@printf $(RED)" -------------- Executable files removed ----------\n"$(EOC)

re: fclean all


# ---------- 
