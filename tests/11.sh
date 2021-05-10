make re

echo
ARG=" 94 5 683  1 284  3 4   34 33 584 ";

echo
#./push_swap $ARG | wc -l

echo
#./push_swap $ARG

echo
./push_swap $ARG | ./checker $ARG

#BONUS
#echo
#./push_swap $ARG | ./checker -v $ARG
