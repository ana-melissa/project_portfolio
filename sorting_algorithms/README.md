# Assignment 3
# Sorting: Putting your affairs in order
This program implements 4 different methods of sorting a randomly generated array: Insertion Sort, Heap Sort, Shell Sort, and Quick Sort.
The array of random numbers is sorted into increasing order and then is printed out. 
This program also keeps track of the number of elements, moves, and compares it took to sort the entire array.
The test harness is written in 'sorting.c'. 


# Building

Files:

- Makefile

- insert.c

	implements Insertion Sort

- insert.h

	specifies the interface to insert.c

- heap.c

	implements Heap Sort

- heap.h

	specifies the interface to heap.c

- quick.c

	implements recursive Quicksort

- quick.h

	specifies the itnerface to quick.c

- set.h

	implements and specifies the interface for the set ADT

- stats.c

	implements the statistics module

- stats.h

	specifies the interface to the statistics module

- shell.c

	implements Shell Sort

- shell.h

	specifies the interface to shell.c

- sorting.c

	contains main() and may contain any other functions necessary to complete the assignment.

- DESIGN.pdf

	Design process of assignment.

- WRITEUP.pdf

	Analysis of assignment results.


Run these commands below to build the program.

---
$make tidy
---
$make clean
---
$make format
---
$make
---


# Running Program
---
$./sorting -a -e -i -s -q -r -n -p
---

-a: Employs all sorting algorithms.

-e: Enables Heap Sort.

-i: Enables Insertion Sort.

-s: Enables Shell Sort.

-q: Enables Quicksort.

-r seed: Set the random seed to seed. The default seed should be 13371453.

-n size: Set the array size to size. The default size should be 100.

-p elements: Prints out number of elements from the array. 

-h: Prints out program usage.


# Output
After inputing the option of the test you want to run in the command line, the seed for the random number generator, the size of the array, 
and the elements in the array, you will get an output in this format:

---
$Sorting Test, # elements, # moves, # compares 
---
$sorted array in columns of 5.
---


