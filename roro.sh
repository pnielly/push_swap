gcc checker.c errors.c builtins.c exec_cmd.c print_lst.c rotate.c reverse_rotate.c swap.c push.c libft.a push_swap.h -o checker
gcc push_swap.c errors.c builtins.c exec_cmd.c print_lst.c rotate.c reverse_rotate.c swap.c push.c libft.a push_swap.h -o push_swap

ARG="2 1 3 6 5 8"; ./push_swap $ARG
