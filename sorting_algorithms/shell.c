//	Shell Sort
//	Assignment 3 Sorting: Putting your affiars in order
//	Ana Melissa
//	Prof. Long
//	CSE 13S Fall 2021
//	10/17/2021
//	This code is based off of Professors Pseudo Code.
//  James Tennant helped me with this code.
#include "set.h"
#include "stats.h"

#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

// Shell Sort Description
// Know the index of the largest gap, return the gap
// For Loop from the max gap down to 1, and return 3 to the i- one
// return i

// define the gap - let it get smaller and smaller
uint32_t gaps(uint32_t *i) {
    uint32_t gap = (pow(3, *i) - 1) / 2;
    if (*i > 0) {
        *i -= 1;
        return gap;
    }
    *i = 0;
    return gap;
}

// define shell sort fucntion with array an d size

void shell_sort(Stats *stats, uint32_t *A, uint32_t n) {
    uint32_t g = log(3 + 2 * n) / log(3);
    for (uint32_t gap = gaps(&g); gap > 0; gap = gaps(&g)) {
        for (uint32_t i = gap; i < n; i += 1) {
            uint32_t j = i;
            // mark the move
            uint32_t temp = A[i];
            //uint32_t temp = move(stats, A[i]);
            while (j >= gap && cmp(stats, temp, A[j - gap]) == -1) {
                //A[j] = move(stats, A[j - gap]);
                A[j] = A[j - gap];
                j -= gap;
            }
            A[j] = move(stats, temp);
        }
    }
    return;
}
