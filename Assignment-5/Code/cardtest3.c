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

	printf("----------------- Testing Great Hall Card ----------------\n");
	memset(&S,23,sizeof(struct gameState));
	memset(&S_Original,23,sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &S);
    //copy S to S_original
    memcpy(&S_Original, &S, sizeof(struct gameState));
    //test Smithy
    cardEffect(great_hall, 0, 0, 0, &S, 0, &bonus);

    //test1
    printf("\nTest 1 ---> Check if player draws a card and it's from their own deck\n\n");
   	printf("Expected handCount = %d\n", S_Original.handCount[0]+1);
    printf("Actual handCount = %d\n\n", S.handCount[0]);
	assertTrue(S_Original.handCount[0], S.handCount[0]);
	printf("\n");
	printf("Expected deckCount = %d\n", S_Original.deckCount[0]-1);
    printf("Actual deckCount = %d\n\n", S.deckCount[0]);
	assertTrue(S_Original.deckCount[0]-1, S.deckCount[0]);
	printf("\n");
	printf("Expected deckCount from other player= %d\n", S_Original.deckCount[1]);
    printf("Actual deckCount from other player = %d\n\n", S.deckCount[1]);
	assertTrue(S_Original.deckCount[1], S.deckCount[1]);
	printf("\n");

	//test2
    printf("\nTest 2 ---> Check if player's number of actions increases by 1\n\n");
   	printf("Expected number of actions = %d\n", S_Original.numActions+1);
    printf("Actual number of actions = %d\n\n", S.numActions);
	assertTrue(S_Original.numActions+1, S.numActions);
	printf("\n");

	//test 3
    printf("\nTest 3 ---> Check if victory piles change\n\n");
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

 	//test 4
    printf("\nTest 4 ---> Check if kingdom card piles change\n\n");
    for (i=0; i < 10; i++)
    {
    	printf("Testing card #%d ...\n", i+1);
    	assertTrue(S_Original.supplyCount[k[i]], S.supplyCount[k[i]]);
    	printf("\n");
    }

 	//test 5
    printf("\nTest 5 ---> Check if other player was affected\n\n");
    //check deck
    printf("Expected deck count = %d\n", S_Original.deckCount[1]);
    printf("Actual deck count = %d\n", S.deckCount[1]);
	assertTrue(S_Original.deckCount[1], S.deckCount[1]);
	printf("\n");
	//check hand
	printf("Expected hand count = %d\n", S_Original.handCount[1]);
    printf("Actual hand count = %d\n", S.handCount[1]);
	assertTrue(S_Original.handCount[1], S.handCount[1]);
	printf("\n");

	//test 6
	printf("\nTest 6 ---> Check if player's score increases by having great_hall\n\n");
   	printf("Expected score = %d\n", scoreFor(0, &S_Original) + 1);
    printf("Actual score = %d\n\n", scoreFor(0, &S));
	assertTrue(scoreFor(0, &S_Original), scoreFor(0, &S));
	printf("\n");

	printf("Expected score of other player = %d\n", scoreFor(1, &S_Original));
    printf("Actual score of other player = %d\n\n", scoreFor(1, &S));
	assertTrue(scoreFor(1, &S_Original), scoreFor(1, &S));
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