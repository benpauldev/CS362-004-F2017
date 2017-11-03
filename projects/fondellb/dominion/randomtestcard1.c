//
//  randomtestcard1.c
//  Dominion_Assignment_4
//
//  Created by Benjamin Fondell on 11/1/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//
// Description: This is a random tester for the whoseTurn function in dominion.c
    
#include <stdio.h>
#include "macros.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
    
int MAX_TESTS = 2000;

int main (int argc, char** argv)
{
    printf("***************************************************************************************************");
    printf("***************************************************************************************************\n");
    
    int test_count = 0;
    struct gameState* state = malloc(sizeof(struct gameState));
    
    for (int i = 1; i <= MAX_TESTS; i++)
    {
        srand(time(NULL));
        int random = rand();
        state->whoseTurn = random;
        
        if (i == 500 || i == 1000 || i == 1500 || i == 2000)
        {
            printf("\nwhoseTurn: Test %i...",i);
        }
        
        //printf("\nwhoseTurn: Test %i.",i);
        MY_ASSERT((whoseTurn(state) == random));
        if (!(whoseTurn(state) == random))
        {
            break;
        }
        test_count++;
    }
    
    MY_ASSERT(test_count == MAX_TESTS);
    if (test_count == MAX_TESTS)
    {
        printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
    }
    else printf("ONE OR MORE TESTS FAILED!\n\n");
    
    printf("***************************************************************************************************");
    printf("***************************************************************************************************\n");
    
    return 0;
}

