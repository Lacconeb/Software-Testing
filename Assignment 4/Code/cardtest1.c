/* 
* --------------------------------------------------------
* Brian Laccone
* CS 372 - Assignment 3
* cardtest1.c
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
	int card;
	int treasureCount;
	int treasureCountOriginal;

	printf("----------------- Testing Adventurer Card ----------------\n");
	memset(&S,23,sizeof(struct gameState));
	memset(&S_Original,23,sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &S);

    memcpy(&S_Original, &S, sizeof(struct gameState));

    cardEffect(adventurer, 0, 0, 0, &S, 0, &bonus);

    //test 1
    printf("\nTest 1 ---> Check if player draws 2 cards\n\n");
    printf("Expected handCount = %d\n", S_Original.handCount[0]+2);
    printf("Actual handCount = %d\n\n", S.handCount[0]);
    assertTrue(S.handCount[0], S_Original.handCount[0]+2);
 	printf("\n");

 	//test 2
    printf("\nTest 2 ---> Check if victory piles change\n\n");
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

 	//test 3
    printf("\nTest 3 ---> Check if kingdom card piles change\n\n");
    for (i=0; i < 10; i++)
    {
    	printf("Testing card #%d ...\n", i+1);
    	assertTrue(S_Original.supplyCount[k[i]], S.supplyCount[k[i]]);
    	printf("\n");
    }


 	//test 4
    printf("\nTest 4 ---> Check if player gained 2 treasure cards\n\n");

    for (i = 0; i < S.handCount[0]; i++) {
        card = S.hand[0][i];
        if (card == copper || card == silver || card == gold) {
            treasureCount++;
        }
    }

    for (i = 0; i < S_Original.handCount[0]; i++) {
        card = S_Original.hand[0][i];
        if (card == copper || card == silver || card == gold) {
            treasureCountOriginal++;
        }
    }

    assertTrue(treasureCountOriginal + 2, treasureCount);
 	printf("\n");

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