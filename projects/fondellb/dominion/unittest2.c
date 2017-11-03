//
//  unittest2.c
//  Dominion-Xcode_Local-Assignment_3
//
//  Created by Benjamin Fondell on 10/21/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//
// Description: This is a unit test for the buyCard function in dominion.c


#include <stdio.h>
#include "macros.h"
#include <stdlib.h>
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
    initializeGame(2, k, 2, &state);
    int test_count = 0;
    
    state.numBuys = 0;
    s = buyCard(5, &state);
    
    printf("\nbuyCard: test for calling buyCard with 0 buys.\n" );
    MY_ASSERT(s == -1);
    if(s == -1)
    {
        
        test_count++;
    }
    
    state.numBuys = 5;
    state.coins = 0;
    s = buyCard(5, &state);
    
    printf("\nbuyCard: test for calling buyCard with 0 coins.\n" );
    MY_ASSERT(s == -1)
    if(s == -1)
    {
        test_count++;
    }
    
    state.coins = 30;
    s = buyCard(5, &state);
    
    printf("\nbuyCard: test passed for calling buyCard with too many coins.\n" );
    MY_ASSERT(s == 0)
    if(s == 0)
    {
        test_count++;
    }
    
    if (test_count == 3)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    else printf("ONE OR MORE TESTS FAILED!\n");
    
    return 0;
    
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");
}
