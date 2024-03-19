#include <ctype.h>
#include <string.h>

int palindrome(char word[]) {
    int i,n,pal=1;
    n=strlen(word);
    for (i=0;i<n/2;i++){
        if (toupper(word[i])!=toupper(word[n-i-1]))
            pal=0;
    }
    return pal;
}