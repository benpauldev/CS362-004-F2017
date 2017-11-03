//
//  cardtest4.c
//  Dominion-Xcode_Local-Assignment_3
//
//  Created by Benjamin Fondell on 10/21/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//
// Description: This is a test of the village car in dominion.c 

#include <stdio.h>
#include "macros.h"
#include "dominion_helpers.h"
#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>

int main (int argc, char** argv)
{
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");
    
    struct gameState state;
    int passed = 0;
    state.numActions = 0;
    state.handCount[0] = 1;
    state.hand[0][0] = village;
    state.deckCount[0] = 1;
    int test_count = 0;
    
    passed = cardEffect(village, 0, 0, 0, &state, 0,NULL);
    
    printf("\ncardEffect(village): test that village was successfully called and returned.\n" );
    MY_ASSERT(passed == 0);
    if (passed == 0)
    {
        test_count++;
    }
    
    printf("\ncardEffect(village): test that village added 2 actions.\n" );
    MY_ASSERT(state.numActions == 2);
    if (state.numActions == 2)
    {
        test_count++;
    }
    
    
    printf("\ncardEffect(village): test that village has been discarded and a card was added to the hand.\n" );
    MY_ASSERT(state.handCount[whoseTurn(&state)] == 1);
    if (state.handCount[whoseTurn(&state)] == 1)
    {
        test_count++;
    }
    
    printf("\ncardEffect(village): test that village drew a card from the deck.\n");
    MY_ASSERT(state.deckCount[0] == 0);
    if (state.deckCount[0] == 0)
    {
        test_count++;
    }
    
    if (test_count == 4)
    {
        printf("\nTEST SUCCESSFULLY COMPLETED\n");
    }
    
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");

    return 0;
    
}
