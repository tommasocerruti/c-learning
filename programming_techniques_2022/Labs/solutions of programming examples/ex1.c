#include <stdio.h>

int charErase (char str[], int pos[]);

// Not required: just to check if the function works!
int main(void) {
  char word[] = "ThisIsAString";
  int positions[] = {7,4,2,0,11,-1};
  int num = charErase(word,positions);

  printf("%s %d",word,num);
  return 0;
}


int charErase (char str[], int pos[]){
  int i,j;

  // Per each position index
  while(pos[i]!=-1){
        j=i;
    // Left-shift of all characters of str starting from pos[i+1]
        while (pos[j+1]!=-1)
        str[pos[j]]=str[pos[j++]];
        str[pos[j]]='';
        j=i+1;
    // Update all indexes>pos[i] to take the left-shift into account
        while(pos[j]!=-1){
            if (pos[j]>pos[j+1])
                pos[j]--;
            j++;
        }
        i++;
    }
    return i;
}
