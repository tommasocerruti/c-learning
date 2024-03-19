#include <stdio.h>
#define LEN 11

int strlen0(char s[]);
int strlen1(char s[]);
int strlen2(char *s);
int strlen3(char *s);

int main() {
    char word[LEN];
    scanf("%s",word);
    printf("Hello, World!\n");
    return strlen0(word)+strlen1(word)-strlen2(&word)-strlen3(&word);
}

int strlen0(char s[]){
    int i=0;
    while (s[i]!='\0')
        i++;
    return i;
}
int strlen1(char s[]){
    int i=0;
    char *pt=s;
    while (*pt!='\0'){
        pt++;
        i++;
    }
    return i;
}
int strlen2(char *s){
    int i=0;
    while (*s != '\0'){
        s++;
        i++;
    }
    return i;
}
int strlen3(char *s){
    char *i=s;
    while (*s!='\0')
        s++;
    return s-i;
}

//{}