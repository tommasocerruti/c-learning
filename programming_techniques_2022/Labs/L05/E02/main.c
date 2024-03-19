#include <stdio.h>
#include <string.h>

#define maxc 200
#define maxv 30 // max number of words
#define maxw 30 // max lenght of words

struct words{
    char enc[maxw], dec[maxw];
};

int check(char token[], char word[], int v, struct words dict[]);

int main() {
    struct words dict[maxv];
    char line[maxc];
    int v,i,val;
    char *token, word[maxw];
    FILE *fp_s, *fp_d, *fp_o;
    fp_s=fopen("../source.txt","r");
    fp_d=fopen("../dictionary.txt","r");
    fp_o=fopen("../output.txt","w");
    if (fp_s==NULL || fp_d==NULL)
        return 1;
    fscanf(fp_d,"%d",&v);
    for (i=0;i<v;i++)
        fscanf(fp_d,"%s %s",dict[i].enc,dict[i].dec);
    while (fgets(line,maxc+1,fp_s)){//for every line in the text
        token=strtok(line," ");//split every line into words
        while (token!=NULL){//for every word in the line
            val=check(token,word,v,dict);//check every word in the dictionary
            fprintf(fp_o,"%s",word);
            if (strcmp(token,word)!=0&&(strlen(token)-val)!=0){
                for (i=val;i<strlen(token);i++)
                    fprintf(fp_o,"%c",token[i]);
            }
            token=strtok(NULL, " ");
            if (token!=NULL)
                fprintf(fp_o," ");
        }
    }
    return 0;
}

int check(char token[], char word[], int v, struct words dict[]){
    int found=0; //found flag
    int i=0;
    char *sub;
    strcpy(word,token);
    while (!found && i<v){//for every word in the dict
        sub=strstr(word,dict[i].dec);
        if (sub){
            memcpy(sub,dict[i].enc,strlen(dict[i].enc)+1);
            found=1;
        }
        i++;
    }
    //in case the substring is not found at the end print the rest
    return (strlen(word)+strlen(dict[i-1].dec)-strlen(dict[i-1].enc));
}