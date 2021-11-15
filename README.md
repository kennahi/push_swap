# push_swap
a program that uses specific instructions to sort the numbers from smallest to biggest.

• The program is composed of 2 stacks named a and b.
• To start with:
◦ a contains a random number of either positive or negative numbers without
any duplicates.
◦ b is empty
• The goal is to sort in ascending order numbers into stack a.
• These are the operations at my disposal:
sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there
is only one or no elements.
sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there
is only one or no elements.
ss : sa and sb at the same time.
pa : push a - take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
pb : push b - take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
ra : rotate a - shift up all elements of stack a by 1. The first element becomes
the last one.
rb : rotate b - shift up all elements of stack b by 1. The first element becomes
the last one.
rr : ra and rb at the same time.
rra : reverse rotate a - shift down all elements of stack a by 1. The last element
becomes the first one.
rrb : reverse rotate b - shift down all elements of stack b by 1. The last element
becomes the first one.
rrr : rra and rrb at the same time.


Check if the instructions are correct with the checker provided using this command
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
change the ARG numbers with whatever numbers you want.
