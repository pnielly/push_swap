gcc checker.c errors.c builtins.c exec_cmd.c print_lst.c rotate.c reverse_rotate.c swap.c push.c libft.a push_swap.h -o checker
gcc push_swap.c errors.c builtins.c exec_cmd.c print_lst.c rotate.c reverse_rotate.c swap.c push.c libft.a push_swap.h -o push_swap

ARG="4 67 3 87 23"; ./push_swap $ARG 
