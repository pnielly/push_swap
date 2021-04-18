make re
echo
ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
echo 
echo
./push_swap 2 1 3 6 5 8 | ./checker 2 1 3 6 5 8
