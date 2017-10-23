//
//  unittest1.c
//  Dominion-Xcode_Local-Assignment_3
//
//  Created by Benjamin Fondell on 10/21/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//
// Description: This is a unit test for the dominion.c isGameOver function.

#include <stdio.h>
#include "macros.h"
#include <stdlib.h>
#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <time.h>
#include "dominion_helpers.h"

int main(){
    
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");
    struct gameState state;
    int s;
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    int test_count = 0;
    
    initializeGame(2, k, 2, &state);
    
    state.supplyCount[province] = 0;
    
    s = isGameOver(&state);
    
    printf("\nisGameOver: test for province supply of 0. \n");
    MY_ASSERT(s==1)
    if(s==1)
    {
        test_count++;
    }
    
    
    state.supplyCount[1] = 0;
    state.supplyCount[5] = 0;
    state.supplyCount[10] = 0;
    s = isGameOver(&state);
    
    printf("\nisGameOver: test for province supply of 0 in 3 piles. \n");
    MY_ASSERT(s==1)
    if(s==1)
    {
        test_count++;
    }
   
    
    if (test_count == 2)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    else printf("ONE OR MORE TESTS FAILED!\n");
    
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");
    
    
    return 0;
}
