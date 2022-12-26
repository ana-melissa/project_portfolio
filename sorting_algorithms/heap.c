//	Heap Sort
//	Assignment 3 Sorting: Putting you affairs in order
//	Ana Melissa
//	Prof. Long
//	CSE 13S Fall 2021
//	10/16/2021

// cite: this code is based off of Professor Long's pseudo code on the assignment.
// James Tennant helped me with this code

#include "set.h"
#include "stats.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

uint32_t max_child(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    uint32_t left = 2 * first;
    uint32_t right = left + 1;
    // record the comparison
    if (right <= last && cmp(stats, A[right - 1], A[left - 1]) == 1) {
        return right;
    }

    return left;
}

// replace the biggest element (which is the first element) with the last element
void fix_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {
    bool found = false;
    uint32_t mother = first;
    uint32_t great = max_child(stats, A, mother, last);

    while (mother <= (last / 2) && !found) {
        // record the comparison
        if (cmp(stats, A[mother - 1], A[great - 1]) == -1) {
            // record the swap
            swap(stats, &A[mother - 1], &A[great - 1]);
            mother = great;
            great = max_child(stats, A, mother, last);
        } else {
            found = true;
        }
    }
    return;
}

// identify first and last in array and then build the heap
// build the max heap
void build_heap(Stats *stats, uint32_t *A, uint32_t first, uint32_t last) {

    for (uint32_t father = last / 2; father > first - 1; father -= 1) {
        fix_heap(stats, A, father, last);
    }
    return;
}

// sort the algorithm using build heap and fix heap
void heap_sort(Stats *stats, uint32_t *A, uint32_t array_size) {
    uint32_t first = 1;
    uint32_t last = array_size;
    build_heap(stats, A, first, last);
    for (uint32_t leaf = last; leaf > first; leaf -= 1) {
        //record the swap
        swap(stats, &A[first - 1], &A[leaf - 1]);
        fix_heap(stats, A, first, leaf - 1);
    }
    return;
}
