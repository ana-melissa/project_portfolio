//	Quick Sort
//	Assignment 3 Sorting: Putting your affairs in order
//	Ana Melissa
//	Prof. Long
//	CSE 13S Fall 2021
//	10/17/2021

//	Cite: this code is based off of Professor Long's psuedo code
// James Tennant helped me with this code.

#include "set.h"
#include "stats.h"

#include <math.h>
#include <stdio.h>
#include <unistd.h>

//determining the pivot point
int partition(Stats *stats, uint32_t *A, uint32_t low, uint32_t high) {
    uint32_t i = low - 1;
    for (uint32_t j = low; j < high; j += 1) {
        if (cmp(stats, A[j - 1], A[high - 1]) == -1) {
            i += 1;
            swap(stats, &A[i - 1], &A[j - 1]);
        }
    }
    swap(stats, &A[i], &A[high - 1]);
    return i + 1;
}
//place elements left or right (low or high) use partition
void quick_sorter(Stats *stats, uint32_t *A, uint32_t low, uint32_t high) {
    if (low < high) {
        uint32_t par = partition(stats, A, low, high);
        quick_sorter(stats, A, low, par - 1);
        quick_sorter(stats, A, par + 1, high);
    }
    return;
}
// sort the algorithm wiht quick sort
void quick_sort(Stats *stats, uint32_t *A, uint32_t n) {
    quick_sorter(stats, A, 1, n);
    return;
}
