/* 
* --------------------------------------------------------
* Brian Laccone
* CS 372 - Assignment 3
* unittest3.c
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

	printf("----------------- Testing isGameOver() ----------------\n");
	memset(&S,23,sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &S);

    //test 1
    printf("\nTest 1 ---> Province supply pile set to 0\n\n");
    //set province supply to 0
    S.supplyCount[province] = 0;
    assertTrue(isGameOver(&S),1);
    printf("\n");

    //reset province supply
    S.supplyCount[province] = 10;

    //test2
    printf("\nTest 2 ---> Set three supply piles to 0\n\n");
    //set first three supply piles to 0
    S.supplyCount[0] = 0;
    S.supplyCount[1] = 0;
    S.supplyCount[2] = 0;
    assertTrue(isGameOver(&S),1);

    //test3
    printf("\nTest 3 ---> Province and all supply piles are not empty\n\n");
    //reset all supply piles to not empty
    S.supplyCount[0] = 10;
    S.supplyCount[1] = 10;
    S.supplyCount[2] = 10;
    assertTrue(isGameOver(&S),0);

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