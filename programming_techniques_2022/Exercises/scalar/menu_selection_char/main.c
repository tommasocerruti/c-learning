#include <stdio.h>
#include <ctype.h>
#define LEN 30
int fa(char row[]);
int fb(char row[]);
int fc(char row[]);

int main() {
    char select, row[LEN+30];
    printf("SELECTOR (A,B,C):");
    scanf("%c",select); //SELECTOR
    gets(row); //ROW
    switch(toupper(select)){
        case 'A': fa(row); break;
        case 'B': fb(row); break;
        case 'C': fc(row); break;
        default: printf("Invalid command"); break;
    }
    return 0;
}

int fa(char row[]){
  return 1;
}
int fb(char row[]){
    return 2;
}
int fc(char row[]){
    return 3;
}