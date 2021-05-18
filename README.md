# push_swap
 42Cursus-push_swap/42Lisboa 

# Intro

 > [subject](subject.pdf)

 This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.
 To succeed you'll have to manipulate various types of algorithms and choose the one (of many) most appropriate solution for an optimized data sorting.

 The **push_swap** project is a very simple and highly effective algorithm project: data will need to be sorted.

## Keywords

 > [Complexity](https://en.wikipedia.org/wiki/Analysis_of_algorithms), [algorithms](https://en.wikipedia.org/wiki/Algorithm), [stacks](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

# Game Rules

 The game is composed of two stacks, named **a** and **b**
 * **a** contains a random number of either positive or negative numbers without duplicates.
 * **b** is empty.
 The goal is to sort the numbers in ascending order into the a stack.

 To do this there are the following operations:

 * ```sa``` : **swap a** - swap the first 2 elements at the top of stack a. Do nothing if there is only one or more elements.
 * ```sb``` : **swap b** - swap the first 2 elements at the top of stack b. Do nothing if there is only one or more elements.
 * ```ss``` : sa and sb at the same time.
 * ```pa``` : **push a** - takes the first element at the top of b and put it at the top of a. Do nothing if b is empty.
 * ```pb``` : **push b** - takes the first element at the top of a and put it at the top of b. Do nothing if b is empty.
 * ```ra``` : **rotate a** - shift up all elements of stackaby 1. The first element becomes the last one.
 * ```rb``` : **rotate b** - shift up all elements of stackbby 1. The first element becomes the last one.
 * ```rr``` : ra and rb at the same time.
 * ```rra``` : **reverse rotate a** - shift down all elements of stackaby 1. The last element becomes the first one.
 * ```rrb``` : **reverse rotate b** - shift down all elements of stackbby 1. The last element becomes the first one.
 * ```rrr``` : rra and rrb at the same time.
