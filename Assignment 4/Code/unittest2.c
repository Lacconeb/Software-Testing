/* 
* --------------------------------------------------------
* Brian Laccone
* CS 372 - Assignment 3
* unittest2.c
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
	int numOfBuys;
	int numOfCoins;
	int numOfProvince;

	printf("----------------- Testing buyCard() ----------------\n");
	memset(&S,23,sizeof(struct gameState));
    initializeGame(numPlayers, k, seed, &S);

    //test 1
    printf("\nTest 1 ---> Set numBuys to 0 before buying\n\n");
    //set state variables to proper numbers for testing
    //want to make sure it only catches the numBuys value
    S.numBuys = 0;
    S.coins = 10;
    S.supplyCount[province] = 10;
    assertTrue(buyCard(province,&S),-1);
    printf("\n");

    //test 2
    printf("\nTest 2 ---> Set province supply count to 0 before buying\n\n");
    //set state variables to proper numbers for testing
    S.numBuys = 1;
    S.coins = 10;
    S.supplyCount[province] = 0;
    assertTrue(buyCard(province,&S),-1);
    printf("\n");

    //test 3
    printf("\nTest 3 ---> Set the coin amount to 0 before buying\n\n");
    //set state variables to proper numbers for testing
    S.numBuys = 1;
    S.coins = 0;
    S.supplyCount[province] = 10;
    assertTrue(buyCard(province,&S),-1);
    printf("\n");

    //test 4
    printf("\nTest 4 ---> numBuys, coins, and province supply count decrease after buying\n\n");
    //set state variables to proper numbers for testing
    S.numBuys = 1;
    S.coins = 10;
    S.supplyCount[province] = 10;
    numOfBuys = S.numBuys;
    numOfCoins = S.coins;
    numOfProvince = S.supplyCount[province];
    buyCard(province,&S);
    //numBuys
    printf("Expected numBuys = %d\n", numOfBuys-1);
    printf("Actual numBuys = %d\n", S.numBuys);
    assertTrue(numOfBuys-1,S.numBuys);
    printf("\n");
    //coins
    printf("Expected coins = %d\n", numOfCoins-8);
    printf("Actual coins = %d\n", S.coins);
    assertTrue(numOfCoins-8,S.coins);
    printf("\n");
    //province supply
    printf("Expected province supply = %d\n", numOfProvince-1);
    printf("Actual province supply = %d\n", S.supplyCount[province]);
    assertTrue(numOfProvince-1,S.supplyCount[province]);
    printf("\n");

    //test 5
    printf("\nTest 5 ---> Check if buying a province increases the current player's score\n\n");
    //set state variables to proper numbers for testing
    S.numBuys = 1;
    S.coins = 10;
    S.supplyCount[province] = 10;
    int p1Score = scoreFor(0,&S);
    int p2Score = scoreFor(1,&S);
    buyCard(province,&S);
    //player whose turn it is
    printf("Expected victory score of player whose turn it is = %d\n", p1Score+6);
    printf("Actual victory score of player whose turn it is = %d\n", scoreFor(0,&S));
    assertTrue(p1Score+6, scoreFor(0,&S));
    printf("\n");
    //other player
    printf("Expected victory score of the other player = %d\n", p2Score);
    printf("Actual victory score of the other player = %d\n", scoreFor(1,&S));
    assertTrue(p2Score, scoreFor(1,&S));
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