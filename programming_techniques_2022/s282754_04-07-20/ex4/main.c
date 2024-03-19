#include <stdio.h>
#include <string.h>

void compressString(char *testo){
    int i=0,l=strlen(testo),count;
    while(i<l){
        i++;count=1;
        while ((i<l) && (testo[i]==testo[i-1])){
            count++;i++;
        }
        if(count==1)
            printf("%c",testo[i-1]);
        else
            printf("%c%d",testo[i-1],count);
    }
}