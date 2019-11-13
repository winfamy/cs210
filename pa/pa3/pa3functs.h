/** pa3functs.h
* ================================================================
* Name: Grady Phillips
* Section: M1A
* Project: Programming Assessment #3 - header file
* =================================================================
*/

#ifndef MYEXE_PA3FUNCTS_H
#define MYEXE_PA3FUNCTS_H

typedef struct MP3_HEADER {
	char header[3];
	char title[30];
	char artist[30];
	char album[30];
	char year[4];
	char comment[30];
	char genre;
} MP3_HEADER;

void getFileName(char * fileName);
MP3_HEADER readHeader(char * filename);
void displayMP3Header(MP3_HEADER mp3);
int updateCommentField(char * fileName, char * comment, MP3_HEADER mp3);
int countLetter(char * field, char c);
MP3_HEADER * mp3Library(int count);
int writeNewFile(MP3_HEADER * mp3Array, int count);
#endif //MYEXE_PA3FUNCTS_H