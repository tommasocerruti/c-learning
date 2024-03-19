#include <stdio.h>

int strcmp0(char str1[], char str2[]);
int strcmp1(char *str1, char *str2);

int main() {
    char str1[10],str2[10];
    int i,j;
    scanf("%s %s",str1,str2);
    i= strcmp0(str1,str2);
    j= strcmp1(&str1,&str2);
    return j*i;
}

int strcmp0(char s0[], char s1[]){
    int i=0;
    while (s0[i]==s1[i] && s0[i]!='\0')
        i++;
    return (s0[i]-s1[i]);
}

int strcmp1(char *s0, char *s1) {
    while ((*s0==*s1) && (*s0!='\0')){
        s0++; s1++;
    }
    return (*s0-*s1);
}
