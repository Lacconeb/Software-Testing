/* 
* --------------------------------------------------------
* Brian Laccone
* CS 372 - Assignment 3
* unittest1.c
* 
* Description: This unit test is 
* 
* 
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
	int deckCount = 0;


	printf("----------------- Testing gainCard() ----------------\n");
	memset(&S,23,sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &S);

    //test 1
    printf("\nTest 1 ---> Add card to deck\n\n");
    deckCount = S.deckCount[0];
    gainCard(province,&S,1,0);
    printf("Expected deckCount = %d\n", deckCount+1);
    printf("Actual deckCount = %d\n\n", S.deckCount[0]);
    assertTrue(deckCount+1,S.deckCount[0]);

    //test 2
    printf("\nTest 2 ---> Add card to discard pile\n\n");
    int discardCount = S.discardCount[0];
    gainCard(province,&S,0,0);
    printf("Expected discardCount = %d\n", discardCount+1);
    printf("Actual discardCount = %d\n\n", S.discardCount[0]);
    assertTrue(discardCount+1,S.discardCount[0]);

    //test3
    printf("\nTest 3 ---> Add card to hand\n\n");
    int handCount = S.handCount[0];
    gainCard(province,&S,2,0);
    printf("Expected handCount = %d\n", handCount+1);
    printf("Actual handCount = %d\n\n", S.handCount[0]);
    assertTrue(handCount+1,S.handCount[0]);

    //test 4
    printf("\nTest 4 ---> Set province supply pile to empty\n\n");
    //set province supply count to 0
    S.supplyCount[province] = 0;
    assertTrue(gainCard(province,&S,0,0), -1);
    //reset province supply count to use in the next 
    S.supplyCount[province] = 8;

    //test 5
    printf("\nTest 5 ---> Province supply decreases after gaining that card\n\n");
    int provinceSupply = S.supplyCount[province];
    gainCard(province,&S,0,0);
    printf("Expected provinceSupply = %d\n", provinceSupply-1);
    printf("Actual provinceSupply = %d\n\n", S.supplyCount[province]);
    assertTrue(provinceSupply-1,S.supplyCount[province]);


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