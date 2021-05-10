make

echo
#echo "$>ARG=\"4\"; ./push_swap $ARG | wc -l"
#ARG=" 1 2 94 5 683  284  3 4   34 33 584 392 43 293 59 399 40"; ./push_swap $ARG | wc -l
ARG="2 1 3"

echo
#./push_swap $ARG | wc -l

echo
#echo "$>ARG=\"4\"; ./push_swap $ARG"
#./push_swap $ARG

echo
#echo "$>ARG=\"4\"; ./push_swap $ARG | ./checker $ARG"
#./push_swap $ARG | ./checker $ARG

#Uncomment the 3 following lines to see the bonus "-v"
#echo
#echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | ./checker -v $ARG"
./push_swap $ARG | ./checker -v $ARG
