//
//  randomtestadventurer.c
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

//RANDOM TESTER FOR ADVENTURER

int MAX_TESTS = 2000;
int TESTS_FAILED = 0;

int treasureCount(int player, struct gameState* state)
{
    int coin_count = 0;
    int index = 0;
    
    for(index = 0; index < state->handCount[player]; index++)
    {
        if((state->hand[player][index] == copper) || (state->hand[player][index] == silver)|| (state->hand[player][index] == gold))
        {
            coin_count++;
        }
    }
    
    return coin_count;
}

int main(){
    
    printf("***************************************************************************************************");
    printf("***************************************************************************************************\n");
    
    int k[10] = {adventurer, gardens, minion, village, embargo, mine, cutpurse, baron, tribute, smithy};
    
    int test = 0;
    int seed = 0;
    srand(time(NULL));
    struct gameState * state;
    
    for (test = 0; test <= MAX_TESTS ; test++ )
    {
        seed = rand();
        state = malloc(sizeof(struct gameState));
        int numPlayers = (rand() % MAX_PLAYERS-1) + 2;
        initializeGame( numPlayers , k , seed , state);
        int player = 0;
  
        state->discardCount[player] = rand() % MAX_DECK;
        state->deckCount[player] = rand() % MAX_DECK;
        state->handCount[player] = rand() % MAX_HAND;
       
            
        int treasureBeforeDeck = fullDeckCount(player, gold, state);
        treasureBeforeDeck = treasureBeforeDeck + fullDeckCount(player, silver, state);
        treasureBeforeDeck = treasureBeforeDeck + fullDeckCount(player, copper, state);
        //printf("**Deck treasure before: %i\n",treasureBeforeDeck);
        int treasureBeforeHand = treasureCount(player, state);
        //printf("**Hand treasure before: %i\n",treasureBeforeHand);
        
       int playedCard = cardEffect(adventurer, 1, 1, 1, state,0,0);
        
        if (playedCard == 0)
        {
            int treasureAfterDeck = fullDeckCount(player, gold, state);
            treasureAfterDeck = treasureAfterDeck + fullDeckCount(player, silver, state);
            treasureAfterDeck = treasureAfterDeck + fullDeckCount(player, copper, state);
            //printf("__Deck treasure after: %i\n",treasureAfterDeck);
            int treasureAfterHand = treasureCount(player,
                                                  state);
            //printf("__Hand treasure after: %i\n",treasureAfterHand);
            
            MY_ASSERT_TOO(treasureAfterDeck == treasureBeforeDeck);
            MY_ASSERT_TOO(treasureAfterHand == (treasureBeforeHand + 2));
            
        }
        
        free(state);
    
        
    }
    
    printf("\n\nadventurerCard: in %i tests %i failed.\n\n",MAX_TESTS,TESTS_FAILED - 1);
    
    printf("***************************************************************************************************");
    printf("***************************************************************************************************");
}
