#include <stdio.h>

int strncmp0(char s0[], char s1[], int n);

int strncmp1(char *s0, char *s1, int n);

int main() {
    printf("Hello, World!\n");
    return 0;
}

int strncmp0(char s0[], char s1[], int n){
    int i=0;
    while (s0[i]==s1[i] && s0[i]!='\0')
        if (i<n)
            i++;
        else
            return 0;
    return (s0[i]-s1[i]);
}

int strncmp1(char *s0, char *s1, int n){int i=0;
    while ((*s0==*s1) && (*s0!='\0')){
        if (i<n)
            {s0++; s1++;}
        else
            return 0;
    }
    return (s0-s1);
}