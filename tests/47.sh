make re

echo
#echo "$>ARG=\"4\"; ./push_swap $ARG | wc -l"
#ARG=" 1 2 94 5 683  284  3 4   34 33 584 392 43 293 59 399 40"; ./push_swap $ARG | wc -l
ARG="17 9 93 80 99 2 5 51 84 4 57 48 14 29 55 35 74 21 94 60 68 63 1 92 23 82 12 67 69 98 52 19 83 97 78 39 75 100 25 24 8 7 41 11 86 44";

echo
./push_swap $ARG | wc -l

echo
#echo "$>ARG=\"4\"; ./push_swap $ARG"
#./push_swap $ARG

echo
#echo "$>ARG=\"4\"; ./push_swap $ARG | ./checker $ARG"
./push_swap $ARG | ./checker $ARG

#Uncomment the 3 following lines to see the bonus "-v"
#echo
#echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | ./checker -v $ARG"
#./push_swap $ARG | ./checker -v $ARG
