/* 
* --------------------------------------------------------
* Brian Laccone
* CS 372 - Assignment 3
* cardtest3.c
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
	struct gameState S_Original;
	int numPlayers = 2;
	int bonus = 0;
	int i;
	
	printf("----------------- Testing Council Room Card ----------------\n");
	memset(&S,23,sizeof(struct gameState));
	memset(&S_Original,23,sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &S);
    //copy S to S_original
    memcpy(&S_Original, &S, sizeof(struct gameState));
    //test Smithy
    cardEffect(council_room, 0, 0, 0, &S, 0, &bonus);

    //test1
    printf("\nTest 1 ---> Check if player draws 4 cards and it's from their own deck\n\n");
   	printf("Expected handCount = %d\n", S_Original.handCount[0]+4);
    printf("Actual handCount = %d\n\n", S.handCount[0]);
	assertTrue(S_Original.handCount[0]+4, S.handCount[0]);
	printf("\n");
	printf("Expected deckCount = %d\n", S_Original.deckCount[0]-4);
    printf("Actual deckCount = %d\n\n", S.deckCount[0]);
	assertTrue(S_Original.deckCount[0]-4, S.deckCount[0]);
	printf("\n");

	//test2
    printf("\nTest 2 ---> Check if other player draws a card and it's from their own deck\n\n");
   	printf("Expected handCount = %d\n", S_Original.handCount[1]+1);
    printf("Actual handCount = %d\n\n", S.handCount[1]);
	assertTrue(S_Original.handCount[1]+1, S.handCount[1]);
	printf("\n");
	printf("Expected deckCount = %d\n", S_Original.deckCount[1]-1);
    printf("Actual deckCount = %d\n\n", S.deckCount[1]);
	assertTrue(S_Original.deckCount[1]-1, S.deckCount[1]);
	printf("\n");

	//test3
    printf("\nTest 3 ---> Check if player's number of buys increases by 1\n\n");
   	printf("Expected number of buys = %d\n", S_Original.numBuys+1);
    printf("Actual number of buys = %d\n\n", S.numBuys);
	assertTrue(S_Original.numBuys+1, S.numBuys);
	printf("\n");
	
	//test 4
    printf("\nTest 4 ---> Check if victory piles change\n\n");
    printf("Expected province count = %d\n", S_Original.supplyCount[province]);
    printf("Actual province count = %d\n\n", S.supplyCount[province]);
    assertTrue(S.supplyCount[province], S_Original.supplyCount[province]);

    printf("\nExpected duchy count = %d\n", S_Original.supplyCount[duchy]);
    printf("Actual duchy count = %d\n\n", S.supplyCount[duchy]);
    assertTrue(S.supplyCount[duchy], S_Original.supplyCount[duchy]);

    printf("\nExpected estate count = %d\n", S_Original.supplyCount[estate]);
    printf("Actual estate count = %d\n\n", S.supplyCount[estate]);
    assertTrue(S.supplyCount[estate], S_Original.supplyCount[estate]);
 	printf("\n");

 	//test 5
    printf("\nTest 5 ---> Check if kingdom card piles change\n\n");
    for (i=0; i < 10; i++)
    {
    	printf("Testing card #%d ...\n", i+1);
    	assertTrue(S_Original.supplyCount[k[i]], S.supplyCount[k[i]]);
    	printf("\n");
    }


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