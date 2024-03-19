#include <stdio.h>
#include <string.h>
#include <ctype.h>

void countAndPrint(char str[], int n);
int isVowel(char c);

// Not required: just to check if it works!
int main(){
    countAndPrint("forExample",4);
}

void countAndPrint(char str[], int n)
{
    int i,j,count,l=strlen(str);
    // Per each possible start of a sub-string of n characters
    for (i=0;i<l-n;i++)
    {
        // Count vowels in the next n characters
        count = 0;
        for (j=i;j<i+n;j++)
            count += isVowel(str[j]);
        // If count is 2...
        if (count==2){
            // Print the sub-string of n charaters that starts from i
            for (j=i;j<i+n;j++)
                printf("%c",str[j]);
            printf("\n");
        }
    }
}

// Returns 1 if c is a vowel, 0 otherwise
int isVowel(char c){
    // Convert to lower-case to be case-independent
    c = tolower(c);
    return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y');
}
