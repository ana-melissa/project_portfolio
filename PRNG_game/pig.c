/*
 
 Assignment 1 Pass the Pigs
 Ana Melissa
 Prof. Long
 CSE 13S - Fall 2021
 10/3/2021

			*/

#include "names.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define SEED 2021

typedef enum { SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER } Position;
const Position pig[7] = { SIDE, SIDE, RAZORBACK, TROTTER, SNOUTER, JOWLER, JOWLER };

int main(void) {

    // prompt the user: how many players

    int input = 0;

    printf("How many players? ");

    scanf("%d", &input);
    // if the input is wrong, use 2 //
    // only 2 to 10 players can play //

    if (input < 2 || input > 10) {
        fprintf(stderr, "Invalid number of players. Using 2 instead.\n");
        input = 2;
    }

    // reset user input to zero
    int input_seed = 0;

    printf("Random seed: ");

    scanf("%d", &input_seed);

    if (input_seed > 0) {
        if (input_seed < 65535) {
            // generate pseudo random number
            srandom(input_seed);
        } else {
            // if input is out of range, use 2021 seed
            fprintf(stderr, "Invalid random seed. Using 2021 instead.\n");

            srandom(2021);
        }
    }

    // make array of scores to keep track of scores
    // array of scores  will only have 10 elements for each player

    int scores[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // for all my players, iterate through the players names
    for (int i = 0; i < input; i = (i + 1) % input) {
        printf("%s rolls the pig...", names[i]);

        if (scores[i] >= 100) {
            printf("\n%s wins with %d points!\n", names[i], scores[i]);
            return 0;
        }

        for (int k = 0; k < 300; k += 1) {

            // character pointers array of words for following print statement index
            char *arr[5] = { "on side\n", "on back", "upright", "on snout", "on ear" };

            int position = pig[random() % 7];

            printf(" pig lands %s", arr[position]);

            if (position == 0) // if position is side, break
            {
                break;
            }

            if (scores[i] >= 100) {
                printf("\n%s wins with %d points!\n", names[i], scores[i]);
                return 0;
            }

            else {
                // add scores
                if (position == 1) {
                    // add scpre 10 for back
                    scores[i] += 10;
                }

                if (position == 2) {
                    // add score 10 for upright
                    scores[i] += 10;
                }

                if (position == 3) {
                    // add score 15 for snout
                    scores[i] += 15;
                }

                if (position == 4) {
                    // add score 5 for ear
                    scores[i] += 5;
                }

                if (scores[i] >= 100) {
                    printf("\n%s wins with %d points!\n", names[i], scores[i]);
                    return 0;
                }
            }
        }
    }
}
