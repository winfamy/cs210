/** lab14main.c
* ===========================================================
* Name: Grady Phillips, 10 Sep, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "lab15functs.h"
#include "lab15fbFuncts.h"
#include <stdio.h>

int main() {
	int * a = &1;
	int arr[DATACOLS][MAXPLAYERS];
	int size = readData(arr[0], arr[1], arr[2]);
	printf("%d players data read.\n", size);

	//The player ID 0 is Aaron Jones and he scored 4 touchdowns in 2017.
	printf("The player ID 0 is %s and he scored %d touchdowns in 2017.\n", getPlayerName(0), arr[2][0]);

	//The player ID 122 is Ezekiel Elliott and he rushed for 983 yards in 2017.
	int playerId = 122;
	printf("The player ID %d is %s and he rushed for %d yards in 2017.\n", playerId, getPlayerName(playerId), arr[1][playerId]);

	//The player with the most yards in 2017 is Kareem Hunt and he had 1327.
	int ydsI = findMaxIndex(arr[1], size);
	printf("The player with the most yards in 2017 is %s and he had %d.\n", getPlayerName(ydsI), arr[1][ydsI]);

	//The player with the most TDs in 2017 is Todd Gurley and he had 13.
	int tdsI = findMaxIndex(arr[2], size);
	printf("The player with the most TDs in 2017 is %s and he had %d.\n", getPlayerName(tdsI), arr[2][tdsI]);

	//The number of players with more than 10 TDs in 2017 is 2.
	int threshold = 10;
	int playerCount = numPlayerOverX(arr[2], threshold, size);
	printf("The number of players with more than %d TDs in 2017 is %d.\n", threshold, playerCount);

	//The number of players with more than 1000 yards in 2017 is 9.
	threshold = 1000;
	playerCount = numPlayerOverX(arr[1], threshold, size);
	printf("The number of players with more than %d yards in 2017 is %d.\n", threshold, playerCount);

	//The number of players with more than 100 attempts in 2017 is 48.
	threshold = 100;
	playerCount = numPlayerOverX(arr[0], threshold, size);
	printf("The number of players with more than %d attempts in 2017 is %d.\n", threshold, playerCount);

	//The player with the most yards per carry (>100 attempts) is Alvin Kamara and he had 6.1.
	threshold = 100;
	int playerIndex = getMaxYardsPerCarryIndex(threshold, arr[1], arr[0]);
	double ydsPerCarry = (double)arr[1][playerIndex] / arr[0][playerIndex];
	printf("The player with the most yards per carry (>%d attempts) is %s and he had %.1lf.\n",
			threshold, getPlayerName(playerIndex), ydsPerCarry);

	//The player with the most yards per carry (>50 attempts) is Dak Prescott and he had 6.3.
	threshold = 50;
	playerIndex = getMaxYardsPerCarryIndex(threshold, arr[1], arr[0]);
	ydsPerCarry = (double)arr[1][playerIndex] / arr[0][playerIndex];
	printf("The player with the most yards per carry (>%d attempts) is %s and he had %.1lf.\n",
	       threshold, getPlayerName(playerIndex), ydsPerCarry);

	//The player with the most yards per carry (>10 attempts) is Cordarrelle Patterson and he had 9.3.
	threshold = 10;
	playerIndex = getMaxYardsPerCarryIndex(threshold, arr[1], arr[0]);
	ydsPerCarry = (double)arr[1][playerIndex] / arr[0][playerIndex];
	printf("The player with the most yards per carry (>%d attempts) is %s and he had %.1lf.\n",
	       threshold, getPlayerName(playerIndex), ydsPerCarry);
}