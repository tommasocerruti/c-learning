#include <stdio.h>
#define MAX 200

int main() {
    char sentence[MAX],c;
    int i=0,lett,val=1,tot=0,op=1;
    scanf("%[^\n]s",sentence);
    c=sentence[i];
    while(c!='\0'){
        while(c!=' ' && c!='\0'){
           i++;
           lett=c-'a'+1;
           val*=lett;
           c=sentence[i];
        }
        if (op)
            op=0;
        else{
            val*=-1;
            op=1;
        }
        tot+=val;
        val=1;
        i++;
        c=sentence[i];
    }
    return tot;
}