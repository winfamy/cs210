/** pa3main.c
* ================================================================
* Name: Grady Phillips
* Section: M1A
* Project: Programming Assessment #3 - main file
* =================================================================
*/

#include "pa3functs.h"
#include <string.h>
#include <stdio.h>

int main()
{
	//char f[1024];
	//getFileName(f);
	//MP3_HEADER mp3 = readHeader(f);
	//
	//char comment[1024];
	//fgets(comment, 30, stdin);
	//updateCommentField("TW.mp3", comment, mp3);

	MP3_HEADER * mp3Array = mp3Library(2);
	writeNewFile(mp3Array, 2);
}