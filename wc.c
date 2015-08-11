/*
 * This program does the same thing that wc or word count
 * command does in the terminal
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	FILE* fp=NULL;
	int nfiles = --argc;
	int argidx = 1;
	char* currfile = "";
	char c;

	/* count of words, lines, characters */
	unsigned long nw=0, nl=0,nc=0;

	if(nfiles==0) {
		fp=stdin; // Standard Input
		nfiles++;
	} else { // Set to first
		currfile=argv[argidx++];
		fp=fopen(currfile, "r");
	}

	while(nfiles>0) { // files left > 0
		if(fp==NULL) {
			fprintf(stderr, "Unable to open Input\n");
			exit(-1);
		}
		nc=nw=nl=0;

		char prevChar;

		while((c=getc(fp))!=EOF){
			// Number of lines
			if (c=='\n')
			{
				nl++;
			}

			// Number of words
			// To count the words in a file, count only those
			// cases where you are moving from a non-white space
			// character to a white-space character
			if (isspace(c) && (!isspace(prevChar))){
				nw++;
			}

			// Number of characters
			nc++;
			prevChar = c;
		}
		printf(" %ld  %ld %ld %s\n",nl,nw,nc,currfile);
		/* next file if exists */
		nfiles--;
		if (nfiles>0)
		{
			currfile=argv[argidx++];
			fp = fopen(currfile, "r");
		}
	}

	return 0;
}