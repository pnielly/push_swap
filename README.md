# Push_swap

Sorting algorithm using 2 stacks, A and B (B empty).
The stack A contains a series of unordered numbers. The aim is to sort the numbers using the minimum movements possible.

Authorized moves:
- sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.</br>
- sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.</br>
- ss : sa and sb at the same time.</br>
- pa (push a): Take the first element at the top of b and put it at the top of a. Do nothing if b is empty.</br>
- pb (push b): Take the first element at the top of a and put it at the top of b. Do nothing if a is empty.</br>
- ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.</br>
- rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.</br>
- rr : ra and rb at the same time.</br>
- rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.</br>
- rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.</br>
- rrr : rra and rrb at the same time.</br>

## Installation

In the root of the repo, type:

```bash
make
```

## Usage

Once the binary is compiled, you can try the binary by typing:
```python
ARG="4 67 3 87 23"; ./push_swap $ARG
```
This will give you the moves to do to order the series of numbers in stack A.</br></br>
You can also type:
```python
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```
This will give you the number of moves required.</br></br>
Finally you can use the checker that will check if the movements result in an ordered series of number:
```python$ARG
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```
## Subject
[push_swap.pdf](https://github.com/pnielly/push_swap/files/8934139/push_swap.pdf)
