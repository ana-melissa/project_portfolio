//	Insertion Sort
// 	Assignment 3 Sorting: Putting your affairs in order
//	Ana Melissa
//	Prof. Long
//	CSE 13S Fall 2021
//	10/10/2021
//
//	cite: This c code is based off of Professor Long's pseudo code

#include "set.h"
#include "stats.h"

#include <inttypes.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void insertion_sort(Stats *stats, uint32_t *A, uint32_t n) {

    for (uint32_t i = 1; i < n; i += 1) {
        uint32_t j = i;

        uint32_t temp = A[i];

        while (j > 0 && cmp(stats, temp, A[j - 1]) == -1) {
            //A[j] = A[j - 1];
            //swap(stats, A[j], A[j - 1]);
            A[j] = move(stats, A[j - 1]);
            j -= 1;

            //A[j] = move(stats, temp);
            //A[j] = move(stats, temp);
        }
        swap(stats, &A[j], &temp);
        //A[j] = move(stats, temp);
    }

    return;
}
