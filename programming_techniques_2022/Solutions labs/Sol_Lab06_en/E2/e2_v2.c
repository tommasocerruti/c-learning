#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_WORD 26
#define N 20
#define MAX_NW 100

#define filein "text.txt"
#define filesq "sequences.txt"

int searchWord(char seq[MAX_WORD], char words[MAX_NW][MAX_WORD], int np);
int readWords(FILE *fp, char words[][MAX_WORD]);
int readWord(FILE *fp, char word[MAX_WORD]);

int main() {
	int i, n, np;
	char seq[MAX_WORD];
	char words[MAX_NW][MAX_WORD];
	FILE *fsq, *fin;

	fin = fopen(filein, "r");
	if (fin == NULL)
		exit(-1);

	np = readWords(fin,words);

	fclose(fin);

	fsq = fopen(filesq, "r");
	if (fsq == NULL)
		exit(-1);

	fscanf(fsq, "%d", &n);

	for (i = 0; i < n; i++) {
		fscanf(fsq, "%s", seq);
		printf("Searching: %s\n", seq);
		if (searchWord(seq,words,np)==0) {
			printf("Sequence not found\n");
		}
	}

	fclose(fsq);

	return 0;
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

int searchWord(char seq[MAX_WORD], char words[MAX_NW][MAX_WORD], int np) {
	int i, count;

	for (i=count=0; i<np; i++) {
		if (stristr(words[i], seq)) {
			printf("\t%s %d\n", words[i], i+1);
			count++;
		}
	}

	return count;
}

int readWords(FILE *fp, char words[MAX_NW][MAX_WORD]) {
	int i, endflag=0;
	for (i=0; i<MAX_NW && !endflag; i++) {
		if (readWord(fp,words[i])<=0) {
			endflag = 1;
			i--; // decrementing it since it will be incremented by the for loop
		}
	}
	return i;
}

int readWord(FILE *fp, char word[MAX_WORD]) {
	int i;
	// Searching first alphanumeric character
	do {
		fscanf(fp, "%c", &word[0]);
	} while (!feof(fp) && !isalnum(word[0]));

	if (feof(fp)) return 0;

	// Searching first non-alphanumeric character
	i=0;
	do {
		fscanf(fp, "%c", &word[++i]);
	} while (!feof(fp) && isalnum(word[i]));
	// adding newline
	word[i] = '\0';
	//  printf("word: %s\n", word);
	return i;
}

