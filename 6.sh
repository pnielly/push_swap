make re

echo
echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | wc -l"
ARG="4 67 3 87 23"; 
./push_swap $ARG | wc -l

echo
echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG"
./push_swap $ARG

echo
echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | ./checker $ARG"
./push_swap $ARG | ./checker $ARG

#Uncomment the 3 following lines to see the bonus "-v"
#echo
#echo "$>ARG=\"4 67 3 87 23\"; ./push_swap $ARG | ./checker -v $ARG"
./push_swap $ARG | ./checker -v $ARG
