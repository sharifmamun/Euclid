#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 100
#define NFIELDS 9

int main()
{
	FILE* fp=NULL;
	char inputFile[]="stateoutflow0708.txt";
	char c;

	// Fields definitions
	char state_code_org[STRSIZE];
	char country_code_org[STRSIZE];
	char state_code_dest[STRSIZE];
	char country_code_dest[STRSIZE];
	char state_abbrv[STRSIZE];
	char state_name[STRSIZE];
	char line[STRSIZE*NFIELDS];

	fp = fopen(inputFile, "r");

	if(fp==NULL) {
		fprintf(stderr, "Unable to open Input\n");
		exit(-1);
	}

	// Skip the first line -- HEADER
	fgets(line, STRSIZE*NFIELDS, fp);

	printf("%-40s %6s\n", "STATE","TOTAL");
	while((c=getc(fp))!=EOF){
		printf("%c",c);
	}

	return 0;
}