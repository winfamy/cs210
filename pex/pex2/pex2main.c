/** pex2main.c
* ===========================================================
* Name: Grady Phillips, 15 Oct, 2019
* Section: M1A
* Project: 
* Purpose: 
* ===========================================================
*/

#include "pex2functs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	DNA * sequence = malloc(sizeof(DNA));
	readFile("../pex/pex2/pex2Data.txt", sequence);
	printf("likely genome match = %d.\n", findBestGenome(sequence->catDNA, sequence->humanDNA, sequence->mouseDNA, "CTTTAGGCCGGTT")); //result= 1
	printf("likely genome match = %d.\n", findBestGenome(sequence->catDNA, sequence->humanDNA, sequence->mouseDNA, "CTTTAGGCCGGG")); //result= 2
	printf("likely genome match = %d.\n", findBestGenome(sequence->catDNA, sequence->humanDNA, sequence->mouseDNA, "CTTAATTCTTTT")); //result= 3
	printf("likely genome match = %d.\n", findBestGenome(sequence->catDNA, sequence->humanDNA, sequence->mouseDNA, "CTTTAG"));
}
