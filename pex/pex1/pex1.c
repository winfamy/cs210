/** pex1.c
* ===========================================================
* Name: Grady Phillips, 09 Sep, 2019
* Section: M1A
* Project: Pex1
* Purpose:
	Adhere to DFCS C Programming Standards to include appropriate commenting
	Use functional decomposition to implement a solution
	Understand function calls and the power of code reuse
	Use selection statements
	Understand indefinite iteration through while loop implementation
* Documentation: None
* ===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pex1.h"

int main() {
	printf("Pig!\n\n");

	// AUTO GRADING STUFF
	int pips;
	printf("Pips to draw: \n");
	scanf("%d", &pips);
	drawDie(pips);

	int die, player, currentTotal, score0, score1;
	printf("Enter die, player, currentTotal, score0, score1: \n");
	scanf("%d %d %d %d %d", &die, &player, &currentTotal, &score0, &score1);

	turnStatus(die, player, currentTotal, score0, score1);
	gameStatus(player, score0, score1);
	printf("+=================+\n");
	printf("| END AUTOGRADING |\n");
	printf("+=================+\n\n\n");
	// AUTO GRADING STUFF

	// GAME CODE
	char opt;                   // char to store roll/hold option
	int dieRoll;                // last die roll
	int turnCount;              // tracks turn count for turns > 40 check
	int turnTotal;              // current turn total, used for both players, reset after turn
	int player0Score;           // player 0 score
	int player1Score;           // player 1 score
	int currentPlayerTurn;      // stores player turn

	// initialize variables
	dieRoll             = 0;
	turnCount           = 0;
	turnTotal           = 0;
	player0Score        = 0;
	player1Score        = 0;
	currentPlayerTurn   = 0;

	// will exit after turnCount > 40
	// also used so ZyBooks doesn't get caught in a loop
	while (turnCount < 40) {
		// display game status at start of turn
		gameStatus(currentPlayerTurn, player0Score, player1Score);

		// get player choice
		printf("Enter choice (r = roll/h = hold): \n");
		scanf(" %c", &opt);

		// if roll chosen, handle that
		while (opt == 'r') {

			// get and output die roll
			dieRoll = rollDie();
			drawDie(dieRoll);

			// handle turntotal and status
			turnTotal += dieRoll;
			turnStatus(dieRoll, currentPlayerTurn, turnTotal, player0Score, player1Score);

			// if pigged out, exit turn
			if (dieRoll != 1) {
				printf("Enter choice (r = roll/h = hold): \n");
				scanf(" %c", &opt);
			} else {
				break;
			}
		}

		// add to score if player did not pig out
		if (dieRoll != 1) {
			if (currentPlayerTurn == 0) {
				player0Score = totalScore(player0Score, turnTotal);
			} else {
				player1Score = totalScore(player1Score, turnTotal);
			}
		}

		// flips player int
		currentPlayerTurn = (currentPlayerTurn + 1) % 2;
		// reset turnTotal
		turnTotal = 0;
		turnCount++;
	}
}

/**   ----------------------------------------------------------
* drawDie, draws an ASCII die given the number of "pips" or dots
* passed as the first parameter.
* @param	int pips 	number of pips to draw
* @return	void
*/
void drawDie(int pips) {
	// save and re-use top and bottom of die frame
	char dieFrame[] = " ------- \n";

	// array of die strings
	char die[6][256] = {
		"|       |\n|   *   |\n|       |\n",
		"| *     |\n|       |\n|     * |\n",
		"| *     |\n|   *   |\n|     * |\n",
		"| *   * |\n|       |\n| *   * |\n",
		"| *   * |\n|   *   |\n| *   * |\n",
		"| *   * |\n| *   * |\n| *   * |\n"
	};

	// prints total die
	printf("%s%s%s", dieFrame, die[pips - 1], dieFrame);
}


/**   ----------------------------------------------------------
* rollDie: returns a random number 1-6
* @return 	Random number 1-6
*/
int rollDie() {
	// seed rand()
	srand(time(0));

	// move rand() output into range 0-5, then move to range 1-6
	return (rand() % 6) + 1;
}


/**   ----------------------------------------------------------  
* turnStatus: provides an update on a player's turn by printing a
* message to the console. The message either notifies the player
* that they have Pigged Out (rolled a 1), or it updates the player
* on their current turn total.
* @param   	int die 			die roll
* @param 	int player 			player number
* @param    int currentTotal	current roll total
* @param    int score0			player 0 score
* @param    int score1			player 1 score
* @return	void
*/ 
void turnStatus(int die, int player, int currentTotal, int score0, int score1) {
	if (die == 1) {
		printf("Player %d pigged out.\n", player);
	} else {
		printf("Current score for player %d = %d.\n", player, currentTotal);
		printf("Total score = %d.\n", player == 0 ? score0 : score1);
	}
}


/**   ----------------------------------------------------------  
* gameStatus: provides an update on the status of the game at
* the conclusion of a player's turn, and either notifies the
* players whose turn it is, or provides a message stating who won the game.
* @param	int player		the player whose turn it is
* @param	int score0		player 0 score
* @param	int score1		player 1 score
* @return	void
*/
void gameStatus(int player, int score0, int score1) {
	printf("Player 0 score: %d\n", score0);
	printf("Player 1 score: %d\n", score1);

	// handle winning or turn switch msg
	if (score0 >= 100) {
		printf("Player 0 won!\n");
		exit(0);
	} else if (score1 >= 100) {
		printf("Player 1 won!\n");
		exit(0);
	} else {
		printf("It is Player %d turn.\n", player);
	}
}

/**   ----------------------------------------------------------  
* totalScore: calculates a player's total score at the conclusion of their turn.
* @param  	int score		player current score
* @param    int turnTotal	player turn total
* @return   Updated player score
*/ 
int totalScore(int score, int turnTotal) {
	// do math lol
	return score + turnTotal;
}