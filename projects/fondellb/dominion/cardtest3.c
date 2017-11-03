//
//  cardtest3.c
//  Dominion-Xcode_Local-Assignment_3
//
//  Created by Benjamin Fondell on 10/21/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//
// Description: This is a test of the dominion.c great_hall cardEffect

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
    state.hand[0][0] = great_hall;
    state.deckCount[0] = 1;
    passed = cardEffect(great_hall, 0, 0, 0, &state, 0, 0);
    int test_count = 0;
    
    printf("\ncardEffect(great_hall): test that great_hall executed and returned.\n" );
    MY_ASSERT(passed == 0);
    if (passed == 0)
    {
        test_count++;
    }
    
    printf("\ncardEffect(great_hall): test that great_hall has been discarded.\n" );
    MY_ASSERT(state.handCount[whoseTurn(&state)] == 1);
    if (state.handCount[whoseTurn(&state)] == 1)
    {
        test_count++;
    }
    
    printf("\ncardEffect(great_hall): test that great_hall increased action by one.\n");
    MY_ASSERT(state.numActions == 1);
    if (state.numActions == 1)
    {
        test_count++;
    }
    
    printf("\ncardEffect(great_hall): test that great_hall drew a card from the deck.\n");
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
