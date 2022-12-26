//	Assignment 3 Sorting: Putting your affairs in order
//	Ana Melissa
//	Prof. Long
//	CSE 13S Fall 2021
//	10/10/2021

// I used Euenge's TA session as giudance for the main function.
// James Tennant helped me with the main sorting function.
#include "set.h"
// empty_set (returns an empty set)
// member_set (asks of some element x is part of set s)
// insert_set (put x into set s)
// delete_set (remove x from s)

#include "heap.h"
#include "insert.h"
#include "quick.h"
#include "shell.h"
#include "stats.h"

#include <inttypes.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define OPTIONS "aeisqr:n:p:h"

#define BIT_MASK 30

// Always start off at zero (all has the value zero)
typedef enum { INSERTION, HEAP, SHELL, QUICK, NUM_COMMANDS } Sorts;

const char *names[] = { "Insertion Sort", "Heap Sort", "Shell Sort", "Quick Sort" };

int main(int argc, char **argv) {

    Stats *stats = malloc(sizeof(Stats));
    // malloc gives back pointer
    if (stats == NULL) {
        return 1;
    }

    // initialize the command tracker set
    Set sett = empty_set();

    int opt = 0;

    // define random seed
    uint32_t random_seed = 13371453;

    // define array length
    uint32_t array_size = 100;

    // define you elements
    uint32_t elements = 100;

    while ((opt = getopt(argc, argv, OPTIONS)) != -1) {
        switch (opt) {
        case 'a':
            // -a: Employs all sorting algorithms
            sett = insert_set(HEAP, sett);
            sett = insert_set(INSERTION, sett);
            sett = insert_set(SHELL, sett);
            sett = insert_set(QUICK, sett);
            break;

        case 'e':
            // -e: Enables Heap Sort
            sett = insert_set(HEAP, sett);
            break;

        case 'i':
            // -i: Enables Insertion Sort
            sett = insert_set(INSERTION, sett);
            break;

        case 's':
            // -s: Enables Shell Sort
            sett = insert_set(SHELL, sett);
            break;

        case 'q':
            // -q: Enables Quicksort
            sett = insert_set(QUICK, sett);
            break;

        case 'r':
            // seed: Set the random seed to seed. The default seed should be 13371453
            random_seed = atoi(optarg);
            break;

        case 'n':
            // Set the array size to size: Default size should be 100
            array_size = atoi(optarg);

            if (array_size > 0) {
                continue;
            } else {
                array_size = 100;
            }
            break;

        case 'p': elements = atoi(optarg); break;

        case 'h':
            printf("SYNOPSIS\n");
            printf("   A collection of comparison-based sorting algorithms.\n");
            printf("\n");
            printf("USAGE\n");
            printf("   ./sorting [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]\n");
            printf("\n");
            printf("OPTIONS\n");
            printf("   -h				display program help and usage.\n");
            printf("   -a				enable all sorts.\n");
            printf("   -e				enable Heap Sort.\n");
            printf("   -i				enable Insertion Sort.\n");
            printf("   -s				enable Shell Sort.\n");
            printf("   -q				enable Quick Sort.\n");
            printf("   -n length		specify number of array elements (default: "
                   "100).\n");
            printf("   -p elements		specify number of elements to print (default: "
                   "100).\n");
            printf("   -r seed			specify random seed (default: 13371453.\n");
            // call funciton
            return 0;
            break;

        default:
            // call help fucntion
            printf("SYNOPSIS\n");
            printf("   A collection of comparison-based sorting algorithms.\n");
            printf("\n");
            printf("USAGE\n");
            printf("   ./sorting [-haeisqn:p:r:] [-n length] [-p elements] [-r seed]\n");
            printf("\n");
            printf("OPTIONS\n");
            printf("   -h               display program help and usage.\n");
            printf("   -a               enable all sorts.\n");
            printf("   -e               enable Heap Sort.\n");
            printf("   -i               enable Insertion Sort.\n");
            printf("   -s               enable Shell Sort.\n");
            printf("   -q               enable Quick Sort.\n");
            printf("   -n length        specify number of array elements (default: 100).\n");
            printf("   -p elements      specify number of elements to print (default: 100).\n");
            printf("   -r seed          specify random seed (default: 13371453.\n");
            return 1;
        }
    }

    // define the array being testing
    uint32_t *A = (uint32_t *) calloc(array_size, sizeof(uint32_t));

    if (A == NULL) {
        return 1;
    }
    srandom(random_seed);
    // pass the random seed through random() and store in array
    for (uint32_t k = 0; k < array_size; k += 1) {

        A[k] = random() & 0x3FFFFFFF;
    }
    //for (Sorts x = INSERTION; x < NUM_COMMANDS; x += 1) {
    //if (member_set(x, sett)) {

    // match the index of x to its corresponding name in array and print
    //printf("%s, ", names[x]);
    if (member_set(HEAP, sett)) {
        reset(stats);
        printf("Heap Sort, ");
        // run and print stats for heap
        heap_sort(stats, A, array_size);
        printf("%d elements, ", array_size);
        printf("%lu moves, ", stats->moves);
        printf("%lu compares\n", stats->compares);

        for (uint32_t i = 0; i < array_size; i += 1) {
            if (i && !(i % 5))
                printf("\n");
            printf("%13" PRIu32, A[i]);
        }
        printf("\n");
    }

    if (member_set(SHELL, sett)) {
        // run and print stats for insertion
        reset(stats);
        printf("Shell Sort, ");
        shell_sort(stats, A, array_size);
        printf("%d elements, ", array_size);
        printf("%lu moves, ", stats->moves);
        printf("%lu compares\n", stats->compares);

        for (uint32_t i = 0; i < array_size; i += 1) {
            if (i && !(i % 5))
                printf("\n");
            printf("%13" PRIu32, A[i]);
        }
        printf("\n");
    }

    if (member_set(INSERTION, sett)) {
        reset(stats);
        printf("Insertion Sort, ");
        // run and print stats for shell
        insertion_sort(stats, A, array_size);
        printf("%d elements, ", array_size);
        printf("%lu moves, ", stats->moves);
        printf("%lu compares\n", stats->compares);
        //printf("%13" PRIu32, A[x]);
        for (uint32_t i = 0; i < array_size; i += 1) {
            if (i && !(i % 5))
                printf("\n");
            printf("%13" PRIu32, A[i]);
        }
        printf("\n");
    }

    if (member_set(QUICK, sett)) {
        reset(stats);
        printf("Quick Sort, ");
        // run and print stats for quick
        quick_sort(stats, A, array_size);
        printf("%d elements, ", array_size);
        printf("%lu moves, ", stats->moves);
        printf("%lu compares\n", stats->compares);

        //printf("%13" PRIu32, A[x]);
        for (uint32_t i = 0; i < array_size; i += 1) {
            if (i && !(i % 5))
                printf("\n");
            printf("%13" PRIu32, A[i]);
        }
        printf("\n");
    }

    free(stats);
    free(A);
    return 0;
}
