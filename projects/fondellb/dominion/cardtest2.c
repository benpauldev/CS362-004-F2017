//
//  cardtest2.c
//  Dominion-Xcode_Local-Assignment_3
//
//  Created by Benjamin Fondell on 10/21/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//
// Description: This is a test of the dominion.c smithyCard

#include <stdio.h>
#include "macros.h"
#include "dominion.h"
#include "rngs.h"
#include <stdlib.h>
#include "dominion_helpers.h"

int main (int argc, char** argv) {
    
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");
    
    struct gameState state;
    int temp;
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    int deckTotal = 0;
    int deckTotalPrev = 0;
    int test_count = 0;
    int discardTotal = 0;
    int discardTotalPrev = 0;
    
    
    initializeGame(2, k, 2, &state);
    printf("\nsmithyCard: test that 3 cards were drawn.\n");
    temp = numHandCards(&state);
    state.hand[whoseTurn(&state)][0] = smithy;
    smithyCard(&state, 0);
    MY_ASSERT(numHandCards(&state) == temp + 2);
    if (numHandCards(&state) == temp + 2)
    {
        test_count++;
    }
    
    initializeGame(2, k, 2, &state);
    printf("\nsmithyCard: test that cards are removed from the deck pile.\n");
    deckTotalPrev = state.deckCount[whoseTurn(&state)];
    state.hand[whoseTurn(&state)][0] = smithy;
    smithyCard(&state,0);
    deckTotal = state.deckCount[whoseTurn(&state)];
    MY_ASSERT(deckTotal == (deckTotalPrev-3));
    if (deckTotal == (deckTotalPrev - 3))
    {
        test_count++;
    }
    
    initializeGame(2, k, 4, &state);
    printf("\smithyCard: test that cards are not taken from the discard pile.\n");
    discardTotalPrev = state.discardCount[whoseTurn(&state)];
    state.hand[whoseTurn(&state)][0] = smithy;
    smithyCard(&state, 0);
    discardTotal = state.discardCount[whoseTurn(&state)];
    MY_ASSERT(discardTotal != (discardTotalPrev - 3));
    if (discardTotal != (discardTotalPrev - 3))
    {
        test_count++;
    }
    
    if (test_count == 3)
    {
        printf("TEST SUCCESSFULLY COMPLETED\n");
    }
    
     printf("***************************************************************************************************");
     printf("***************************************************************************************************");
    
    return 0;
    
}
