//
//  unittest3.c
//  Dominion-Xcode_Local-Assignment_3
//
//  Created by Benjamin Fondell on 10/21/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//
// Description: This is a test for the whoseTurn function in dominion.c

#include <stdio.h>
#include "macros.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv)
{
    printf("***************************************************************************************************");
    printf("***************************************************************************************************");
    int test_count = 0;
    struct gameState* state = malloc(sizeof(struct gameState));
    
    for (int i = 1; i <= 3; i++)
    {
        srand(time(NULL));
        int random = rand();
        state->whoseTurn = random;
        printf("\nwhoseTurn: Test %i.\n",i);
        MY_ASSERT((whoseTurn(state) == random));
        if (!(whoseTurn(state) == random))
        {
            break;
        }
        test_count++;
    }
    
    MY_ASSERT(test_count == 3);
    if (test_count == 3)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    else printf("ONE OR MORE TESTS FAILED!\n");
    
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");
    
    return 0;
}
