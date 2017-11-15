//
//  randomtestcard2.c
//  Dominion_Assignment_4
//
//  Created by Benjamin Fondell on 11/1/17.
//  Copyright © 2017 Benjamin Fondell. All rights reserved.
//

#include <stdio.h>
#include "macros.h"
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//RANDOM TESTER FOR SMITHY CARD

int MAX_TESTS = 2000;
int TESTS_FAILED = 0;

int main(){
    
    printf("***************************************************************************************************");
    printf("***************************************************************************************************");
    
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    
    int test = 0;
    int numPlayers = 0;
    srand(time(NULL));
    int seed = 0;
    struct gameState state;
    
    for (test = 0; test <= MAX_TESTS ; test++ )
    {
        numPlayers = (rand() % MAX_PLAYERS - 1) + 2;
        seed = rand();
        initializeGame( numPlayers , k , seed , &state);
        int player = 0;
        
        for (player = 0; player < numPlayers; player++)
        {
           
            state.discardCount[player] = rand() % MAX_DECK;
            state.deckCount[player] = rand() % MAX_DECK;
            state.handCount[player] = rand() % MAX_HAND;
            
            if(seed % 3 == 0)
            {
                    state.deckCount[player] = 0;
            }
            
            int previousDeck = state.deckCount[player];
            //printf("Previous Deck: %i\n",previousDeck);
            int previousHand = state.handCount[player];
            //printf("Previous Hand: %i\n",previousHand);
            int prevActions = state.numActions;
            //printf("Previous Actions: %i\n",prevActions);
            int playedCard = 0;
            
            state.hand[player][0] = smithy;
            playedCard = playSmithy(&state, 0);
            
            if (playedCard == 0)
            {
                int afterDeck = state.deckCount[player];
                //printf("After Deck: %i\n",afterDeck);
                int afterHand = state.handCount[player];
                //printf("After Hand: %i\n",afterHand);
                int afterActions = state.numActions;
                //printf("After Actions: %i\n",afterActions);
                
                MY_ASSERT_TOO((afterDeck == (previousDeck - 3)) || previousDeck == 0);
                MY_ASSERT_TOO(afterHand == (previousHand + 2));
                MY_ASSERT_TOO(afterActions == (prevActions - 1));
                
            }
        }
        
    }
    
    printf("\n\nsmithyCard: in %i tests %i failed.\n\n",MAX_TESTS,TESTS_FAILED - 1);
    
    printf("***************************************************************************************************");
    printf("***************************************************************************************************");
}
