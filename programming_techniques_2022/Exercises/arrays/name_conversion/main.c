#include <string.h>
#include <stdio.h>

#define MMAX 6
#define NMAX 20
#define NUM 50

typedef struct {
    char matricola[MMAX+1], name[NMAX+1];
} t_stud;

int matrName(char m[], t_stud table[], int n, char name[]);

int main(void){
    char m[MMAX],name[NMAX]="";
    t_stud table[NUM];
    int n;
    scanf("%s",&m);
    if (matrName(m,table, n, name))
        printf("%s",name);

}

int matrName(char m[], t_stud table[], int n, char name[]){
    int i;
    for (i=0; i<n; i++) {
        if (strcmp(m,table[i].matricola)==0) {
            strcpy (n, table[i].name);
            return 1;
        }
        return 0;
    }