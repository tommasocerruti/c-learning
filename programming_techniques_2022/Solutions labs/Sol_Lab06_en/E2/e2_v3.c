#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_MATCH 20
#define MAX_WORD 26
#define MAX_ROW 201
#define MAX_INC 6
#define N 20

#define filein "text.txt"
#define filesq "sequences.txt"

typedef struct match_ {
	char str[MAX_WORD];
	int pos;
} match_t;

typedef struct index_ {
	char incipit[MAX_INC];
	int incipit_length;
	int n_match;
	match_t match[MAX_MATCH];
} index_t;

int readSequences(index_t index[N]);
int processLine(char row[MAX_ROW], index_t index[N], int n, int wordCount);
void printMatch(index_t index[N], int n);

int main() {
	index_t index[N];
	int n, wordPos = 0;
	char row[MAX_ROW];
	FILE *fin;

	n = readSequences(index);

	fin = fopen(filein, "r");
	if (fin == NULL)
		exit(-1);

	while(fgets(row, MAX_ROW, fin) != NULL){
		wordPos = processLine(row, index, n, wordPos);
	}

	fclose(fin);

	printMatch(index, n);

	return 0;
}

int readSequences(index_t index[N]) {
	FILE *fp;
	int i, n;

	fp = fopen(filesq, "r");
	if (fp == NULL) {
		printf("Error reading sequences file\n");
		exit(-1);
	}

	if (fscanf(fp, "%d", &n) != 1) {
		printf("Error readin sequences numbers\n");
		exit(1);
	}

	for (i = 0; i < n; i++) {
		fscanf(fp, "%s", index[i].incipit);
		index[i].incipit_length = strlen(index[i].incipit);
		index[i].n_match = 0;
	}
	fclose(fp);
	return n;
}

int findWord(char row[], int lun, int i, char currWord[MAX_WORD]) {
	int wordLength=0;

	while((wordLength+i) < lun && wordLength < MAX_WORD && isalnum(row[(wordLength+i)])) {
		currWord[wordLength] = row[i+wordLength];
		wordLength++;
	}
	currWord[wordLength] = '\0';
	return wordLength;
}

int stristr(char *s1, char *s2) {
	int i = 0, j = 0;

	while(s1[i] != '\0'  && s2[j] != '\0') {
		if(tolower(s1[i]) == tolower(s2[j])) {
			j++ ;
		} else {
			j = 0 ;
		}
		i++;
	}
	return (s2[j] == '\0') ;
}

void searchSeq(index_t index[N], int n, char currWord[MAX_WORD], int wordPos) {
	int i, keepOn=1;
	for(i=0;i<n && keepOn;i++) {
		if (stristr(currWord, index[i].incipit)) {
			if(index[i].n_match < MAX_MATCH) {
				strcpy(index[i].match[index[i].n_match].str, currWord);
				index[i].match[index[i].n_match++].pos = wordPos;
				keepOn =0;
			}
		}
	}
	return;
}

int processLine(char row[MAX_ROW], index_t index[N], int n, int wordPos) {
	int i, lun = strlen(row), wordLength;
	char currWord[MAX_WORD] = {'\0'};

	// For each character in a row
	for (i=0; i<lun; i++) {

		// if at current position an alphanumeric string begins
		if (isalnum(row[i])) {
			wordPos++;
			wordLength = findWord(row, lun, i, currWord);
			searchSeq(index, n, currWord, wordPos);
			i += wordLength-1;
		}
	}
	return wordPos;
}

void printMatch(index_t index[N], int n){
	int i, j;
	for(i=0;i<n;i++) {
		if (index[i].n_match != 0){
			printf("%s\n", index[i].incipit);
			for(j=0;j<index[i].n_match;j++) {
				printf("\t%s %d\n", index[i].match[j].str, index[i].match[j].pos);
			}
		}
	}
}
