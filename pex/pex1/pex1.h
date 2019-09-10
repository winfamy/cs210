/** pex1.h
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
* ===========================================================
*/

#ifndef C_PEX1_H
#define C_PEX1_H

void drawDie(int pips);
int rollDie();
void turnStatus(int die, int player, int currentTotal, int score0, int score1);
void gameStatus(int player, int score0, int score1);
int totalScore(int score, int turnTotal);

#endif //C_PEX1_H
