/* 
* --------------------------------------------------------
* Brian Laccone
* CS 372 - Assignment 3
* unittest4.c
* --------------------------------------------------------
*/

#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>

//integer to keep track of how many tests fail
int failCount = 0;

//function to check if two integers are equal
//better than using assert in c because it won't stop the program
void assertTrue(int a, int b)
{

	if (a == b)
	{
		printf("Test: PASSED\n");
	}
	else
	{
		failCount++;
		printf("Test: FAILED\n");
	}

}

int main()
{

	int seed = 100;
	int k[10] = {adventurer, council_room, feast, gardens, mine, 
				remodel, smithy, village, baron, great_hall};
	struct gameState S;
	int numPlayers = 2;
	int preShuffle;
	int postShuffle;
	int deckCount;

	printf("----------------- Testing shuffle() ----------------\n");
	memset(&S,23,sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &S);

    //test 1
    printf("\nTest 1 ---> Set player's deckCount to 0\n\n");
    S.deckCount[0] = 0;
    assertTrue(shuffle(0,&S), -1);
 	printf("\n");

 	//test2
    printf("\nTest 2 ---> Make sure the deck is actually shuffled\n\n");
    S.deckCount[0] = 20;
    preShuffle = S.deck[0][0];
    shuffle(0,&S);
    postShuffle = S.deck[0][0];

    if (preShuffle != postShuffle)
    {
    	assertTrue(1,1);
    }
    else
    {
    	assertTrue(0,1);
    }
    printf("\n");

    //test3
    printf("\nTest 3 ---> Test if the player has the same amount of cards in the deck before and after shuffling\n\n");
    S.deckCount[0] = 20;
    deckCount = 20;
    shuffle(0,&S);
    printf("Expected deckCount = %d\n", deckCount);
    printf("Actual deckCount = %d\n\n", S.deckCount[0]);
    assertTrue(S.deckCount[0], 20);
    printf("\n");    


    if (failCount) 
	{
        printf("\nTEST FAILED\n");
        printf("FAILS: %d\n\n",failCount);
    }
    else 
    {
        printf("\nTEST SUCCESSFULLY COMPLETED\n\n");
    }

	return 0;
}