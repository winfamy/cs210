/** pa3functs.c
* ================================================================
* Name: Grady Phillips
* Section: M1A
* Project: Programming Assessment #3 - function file
* =================================================================
*/

#include "pa3functs.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void getFileName(char * filename) {
	FILE * fp;
	do {
		printf("Enter filename: ");
		scanf("%s", filename);
		char ch = '\0'; while ((ch = getchar()) != '\n' && ch != EOF);
		fp = fopen(filename, "rb");
		if (fp == NULL)
			printf("Error opening file.\n");
	} while (fp == NULL);
}

void displayMP3Header(MP3_HEADER mp3) {
	printf("Title: %-.30s\n",  mp3.title);
	printf("Artist: %-.30s\n", mp3.artist);
	printf("Album: %-.30s\n", mp3.album);
	printf("Year: %-.4s\n", mp3.year);
	printf("Comment: %-.30s\n", mp3.comment);
}

MP3_HEADER readHeader(char * filename) {
	MP3_HEADER mp3;
	FILE * fp = fopen(filename, "rb");
	fseek(fp, -128, SEEK_END);
	fread(&mp3, sizeof(MP3_HEADER), 1, fp);
	fclose(fp);
	return mp3;
}


int updateCommentField(char * filename, char * comment, MP3_HEADER mp3) {
	strncpy(mp3.comment, comment, 30);
	displayMP3Header(mp3);
	FILE * fp = fopen(filename, "r+");
	fseek(fp, -128, SEEK_END);
	fwrite(&mp3, sizeof(MP3_HEADER), 1, fp);
	fclose(fp);
	return 0;
}

int countLetter(char * field, char c) {
	int count = 0;
	for (int i = 0; i < strlen(field); ++i) {
		if (field[i] == c)
			count++;
	}

	return count;
}

MP3_HEADER * mp3Library(int count) {
	char f[1024];
	MP3_HEADER * mp3Array = malloc(sizeof(MP3_HEADER) * count);
	for (int i = 0; i < count; ++i) {
		getFileName(f);
		mp3Array[i] = readHeader(f);
	}

	return mp3Array;
}

int writeNewFile(MP3_HEADER * mp3Array, int count) {
	if (count < 1) {
		printf("what r u doing\n");
		return 0;
	}

	FILE * fp = fopen("outputFile.txt", "w");
	fwrite(mp3Array, sizeof(MP3_HEADER) * count, 1, fp);
	fclose(fp);
	return count;
}