#include <stdio.h>
#include <string.h>

int count(char *words[], int nwords, char *wordToSearch);

int main(int argc, char *argv[]) {
    
    int n = count(argv, argc, argv[argc-1]);
    printf("%d",n);
    
    return 0;
}

int count(char *words[], int nwords, char *wordToSearch)
{
    int i,j,n=0;
    char* p; // Pointer to char

    // Per all arguments before the last one (argv[0] excluded)
    for (i=1;i<nwords-1;i++)
    {
        p = words[i]; // p now points to the beginning of the i-th argument
        while(p!=NULL)
        {
            // check whether wordToSearch is a substring of the string pointed by p
            p = strstr(p,wordToSearch);
            // p now points to the first occurrence of the sub-string (if any)
            if (p!=NULL)
            {
                n++; // Increment number of occurrences of the sub-string
                p++; // Increment p by 1 --> let's check the rest of the string (there could be more than one occurrence)
            }
        }
    }
    
    return n;
}
