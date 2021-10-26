# push_swap
 Sort data on a stack, with a limited set of instructions

The following functions are allowed to use: write, read, malloc, free, exit

---------------------------------------------------------------------

**Game rules:**

The game is composed of 2 stacks named **A** and **B**.

**A** contains a random number of either positive or negative numbers without any duplicates, given as arguments

**B** is empty

The goal is to sort in ascending order numbers into stack **A**.

**To do this only following operations are allowed:**

**sa** : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).

**sb** : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).

**ss** : sa and sb at the same time.

**pa** : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.

**pb** : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.

**ra** : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.

**rb** : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.

**rr** : ra and rb at the same time.

**rra** : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one

**rrb** : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.

**rrr** : rra and rrb at the same time.

The executable file named **push_swap**

```
$>make
$>./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
$>./push_swap 0 one 2 3
Error
$>
```
checker
---------------------------------------------------------------------


**checker** gets as an argument the stack **A** formatted as a list of integers

**checker** waits and reads instructions on the standard input

If after executing those instructions, stack **A** is sorted and **B** is empty, then
**checker** must display "OK".  

In other case, **checker** displays "KO"

```
$>make bonus
$>./checker 3 2 1 0
rra
pb
sa
rra
pa
OK
$>./checker 3 2 1 0
sa
rra
pb
KO
$>./checker 3 2 one 0
Error

```
