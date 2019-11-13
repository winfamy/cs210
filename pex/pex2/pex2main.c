/** pex2main.c
* ===========================================================
* Name: Grady Phillips, 15 Oct, 2019
* Section: M1A
* Project: 
* Purpose:
	Demonstrate file I/O, structs, and string manipulation
	Understand the relationship between C header files and C implementation files
	Understand function calls and the power of code reuse
	Basic understanding of hamming distance and similarity scores, and their relationship to genome sequences
* Documentation: None
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
