#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXD 30
#define WORD_LENGTH 50
#define ROW_LENGTH 201
#define FDIC "dictionary.txt"
#define FIN  "source.txt"
#define FOUT "reencoded.txt"

typedef struct {
	char term[WORD_LENGTH];
	char token[WORD_LENGTH];
} entry;

int loadDictionary(entry dict[], char fileDict[]);
void processRow(char row[], entry dict[], int nd, FILE *fout);
int compare(char row[], int start, char term[], int l);
int comparePointer(char row[], int start, char term[], int l);

int main(void) {
	FILE *fin, *fout;
	entry dict[MAXD];
	int nd;
	char row[ROW_LENGTH];

	nd = loadDictionary(dict, FDIC);
	fin = fopen(FIN, "r");
	fout = fopen(FOUT, "w");

	if (fin==NULL || fout==NULL ) exit(-1);

	while(fgets(row, ROW_LENGTH, fin) != NULL){
		processRow(row, dict, nd, fout);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}

int loadDictionary(entry dict[], char *fileDict) {
	int nd, i;
	FILE *in = fopen(fileDict, "r");
	if (in == NULL)  return 0;

	fscanf(in, "%d", &nd);
	for (i=0; i<nd; i++)
		fscanf(in, "%s %s", dict[i].token, dict[i].term);
	fclose(in);
	return nd;
}

int compare(char row[], int start, char term[], int l) {
	int j;

	for (j=0; j<l; j++) {
		if (row[start+j] != term[j])
			return 0;
	}
	return 1;
}

int comparePointer(char row[], int start, char term[], int l) {
	return (strncmp(row+start,term,l)==0);
}

void processRow(char row[], entry dict[], int nd, FILE *fout) {
	int i, j, len, match;

	/* for each character in row */
	for (i=0; row[i]!='\0'; i++) {
		match = 0;
		/* ... determine if there is a match with a term in the dictionary */
		for (j=0; j<nd; j++) {
			len = strlen(dict[j].term);
			if (compare(row,i,dict[j].term,len)) {
				match = 1; /* If there is such a match, stop the search */
				break;
			}
		}
		/* if a match is found ... */
		if (match) {
			/* ... put the subsitutive token in the output file and increment starting point by len characters (-1 to compensate for the increment of the for loop) */
			fprintf(fout, "%s", dict[j].token);
			i += (len-1);
		} else
			/* ... otherwise write only the current character for which it was not possible to find a match (the increment will be performed by the for loop) */
			fprintf(fout, "%c", row[i]);
	}
}

