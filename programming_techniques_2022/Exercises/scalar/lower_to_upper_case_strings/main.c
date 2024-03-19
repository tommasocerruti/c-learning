#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAXL 30

int main() {
    int i;
    char word[MAXL+1];
    scanf("%s",&word);
    printf("Before: %s\n",word);
    for (i=0;i< strlen(word);i++)
        word[i]= toupper(word[i]);
    printf("After: %s",word);
    return 0;
}