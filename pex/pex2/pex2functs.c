/** pex2.c
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

/**   ----------------------------------------------------------
* Reads a file into a DNA struct array
* @param		char	filename	the file to read from
* @param		DNA*	sequence	DNA array
*/
void readFile(char filename[], DNA * sequences) {
	FILE * fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Could not open file %s.\n", filename);
		exit(1);
	}

	fscanf(fp, "%s", sequences->humanDNA);
	fscanf(fp, "%s", sequences->mouseDNA);
	fscanf(fp, "%s", sequences->catDNA);
}

/**   ----------------------------------------------------------
* Returns hamming distance between two DNA strings, i.e. number of characters
* that are different. Returns -1 on diff string length.
* @param    	str	str1			string 1 to compare
* @param		str	str2			string 2 to compare
* @return		int	hammingDist		the number of characters that diff
*/
int hammingDistance(char* str1, char* str2) {
	if (strlen(str1) != strlen(str2)) {
		return -1;
	}

	int diff = 0;
	for (int i = 0; i < strlen(str1); ++i) {
		if (str1[i] != str2[i]) {
			diff++;
		}
	}

	return diff;
}

/**   ----------------------------------------------------------
* Computes and returns the similarity score between two strings -> (length - hamming) / length
* @param          str	seq1	str1
* @param          str	seq2	str2
* @return         int	simscore
*/
float similarityScore(char* seq1, char* seq2) {
	int hamming = hammingDistance(seq1, seq2);
	if (hamming == -1) {
		return 0;
	}

	float length = (float)strlen(seq1);
	return (length - hamming) / length;
}

/**   ----------------------------------------------------------
* Count number of matches in two genomes given a genome, a sequence, and a minimum similarity score
* @param			string	genome		the genome to check
* @param			string	seq			the seq to compare with
* @param			float	minScore	the minimum simscore
* @return         	int		number of matches
*/
int countMatches(char* genome, char* seq, float minScore) {
	int matches = 0;
	int timesToIter = strlen(genome) - strlen(seq) + 1;
	char * substr = malloc(sizeof(char) * strlen(seq));

	for (int i = 0; i < timesToIter; ++i) {
		// iterate over length of seq
		// to build a substr of genome
		// of length strlen(seq) at offset i
		for (int j = 0; j < strlen(seq); ++j) {
			substr[j] = genome[j + i];
		}
		substr[strlen(seq)] = '\0';

		if (similarityScore(substr, seq) >= minScore) {
			matches++;
		}
	}

	return matches;
}

/**   ----------------------------------------------------------
* Finds the highest simscore with a given genom and sequence
* @param          string	genome	the genome to check against
* @param		  string	seq		the seq to compare with
* @return         minscore	the minimum simscore
*/
float findBestMatch(char* genome, char* seq) {
	float max = 0;
	int timesToIter = strlen(genome) - strlen(seq) + 1;
	char * substr = malloc(sizeof(char) * strlen(seq));

	for (int i = 0; i < timesToIter; ++i) {
		// iterate over length of seq
		// to build a substr of genome
		// of length strlen(seq) at offset i
		for (int j = 0; j < strlen(seq); ++j) {
			substr[j] = genome[j + i];
		}
		substr[strlen(seq)] = '\0';

		if (similarityScore(substr, seq) >= max) {
			max = similarityScore(substr, seq);
		}
	}

	return max;
}

/**   ----------------------------------------------------------
* takes 3 known genomes (HUMANDNA, MOUSEDNA, CATDNA) and a
* sequence to determine which genome is the best match.
* @param		string	genome1		human dna
* @param		string	genome2		mouse dna
* @param		string	genome3		cat dna
* @return		string	unknownSeq	the seq to check against
*/
int findBestGenome(char* genome1, char* genome2, char* genome3, char* unknownSeq) {
	float score1 = findBestMatch(genome1, unknownSeq);
	float score2 = findBestMatch(genome2, unknownSeq);
	float score3 = findBestMatch(genome3, unknownSeq);
	if (score1 > score2 && score1 > score3) {
		return 1;
	} else if (score2 > score1 && score2 > score3) {
		return 2;
	} else if (score3 > score1 && score3 > score2) {
		return 3;
	}

	return 0;
}