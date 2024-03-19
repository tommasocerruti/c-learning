#include <stdio.h>
#include <string.h>

char *strstrstr(char s[], char c[]);

int main() {
    char word1[10],word2[10];
    scanf("%s %s",word1,word2);
    printf("%s",strstrstr(word1,word2));
    return 0;
}

char *strstrstr(char s[], char c[]){
    int i, lens, lenc;
    lens=strlen(s);
    lenc=strlen(c);
    for (i=0;i<=lens-lenc;i++){
        if (strncmp(&s[i],c,lenc)==0)
            return &s[i];
        return NULL;
    }
}