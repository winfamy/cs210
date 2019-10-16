/** pex2.h
* ===========================================================
* Name: Grady Phillips, 15 Oct, 2019
* Section: M1A
* Project: PEX2
* Purpose:
	Demonstrate file I/O, structs, and string manipulation
	Understand the relationship between C header files and C implementation files
	Understand function calls and the power of code reuse
	Basic understanding of hamming distance and similarity scores, and their relationship to genome sequences
* ===========================================================
*/

#ifndef C_PEX2FUNCTS_H
#define C_PEX2FUNCTS_H

#include <string.h>

typedef struct DNA {
	char humanDNA[1024];
	char mouseDNA[1024];
	char catDNA[1024];
} DNA;

/**   ----------------------------------------------------------
* Reads a file into a DNA struct array
* @param		char	filename	the file to read from
* @param		DNA*	sequence	DNA array
*/
void readFile(char filename[], DNA* sequence);

/**   ----------------------------------------------------------
* Returns hamming distance between two DNA strings, i.e. number of characters
* that are different.
* @param    	str	str1			string 1 to compare
* @param		str	str2			string 2 to compare
* @return		int	hammingDist		the number of characters that diff
*/
int hammingDistance(char* str1, char* str2);

/**   ----------------------------------------------------------  
* Computes and returns the similarity score between two strings -> (length - hamming) / length  
* @param          str	seq1	str1
* @param          str	seq2	str2
* @return         int	simscore
*/ 
float similarityScore(char* seq1, char* seq2);

/**   ----------------------------------------------------------  
* Count number of matches in two genomes given a genome, a sequence, and a minimum similarity score
* @param			string	genome		the genome to check
* @param			string	seq			the seq to compare with
* @param			float	minScore	the minimum simscore
* @return         	int		number of matches
*/ 
int countMatches(char* genome, char* seq, float minScore);

/**   ----------------------------------------------------------
* Finds the highest simscore with a given genom and sequence
* @param          string	genome	the genome to check against
* @param		  string	seq		the seq to compare with
* @return         minscore	the minimum simscore
*/
float findBestMatch(char* genome, char* seq);

/**   ----------------------------------------------------------  
* takes 3 known genomes (HUMANDNA, MOUSEDNA, CATDNA) and a
* sequence to determine which genome is the best match.
* @param		string	genome1		human dna
* @param		string	genome2		mouse dna
* @param		string	genome3		cat dna
* @return		string	unknownSeq	the seq to check against
*/ 
int findBestGenome(char* genome1, char* genome2, char* genome3, char* unknownSeq);
void readFileSol(char filename[], DNA * sequences);

#endif //C_PEX2FUNCTS_H
