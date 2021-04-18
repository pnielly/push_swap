make re
echo
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
echo
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
