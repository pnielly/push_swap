make re

echo
echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | wc -l"
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

echo
echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG"
ARG="4 67 3 87 23"; ./push_swap $ARG

echo
echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | ./checker $ARG"
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

echo
echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | ./checker -v $ARG"
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker -v $ARG
