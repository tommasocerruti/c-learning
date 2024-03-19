#include <stdio.h>
#include <string.h>
#define maxline 25
#define maxword 20

int main() {
    FILE *fp= fopen("../tolls.txt","r");
    int i=0;
    char checkpoint1[maxline][maxword], checkpoint2[maxline][maxword];
    float tolls[maxline];
    char entry[maxword], exit[maxword], section2[maxword], section3[maxword];
    float fare=0.00;
    int j, entry_pos, exit_pos, found=0, medium_pos=-1;
    while ((fscanf(fp,"%s %s %f",checkpoint1[i],checkpoint2[i],&tolls[i])==3)&&i<maxline)
        i++;
    printf("Entry point:"); scanf("%s",&entry);
    printf("Exit point:"); scanf("%s",&exit);
    for (j=0;j<i;j++) {
        if (strcmp(checkpoint1[j], entry) == 0 && (!found)){
            entry_pos=j;
            found=1;
        }
    }
    if (!found){
        printf("Warning: entry point not found.");
        return 1;
    }
    found=0;
    for (j=0;j<i;j++) {
        if (strcmp(checkpoint2[j], exit) == 0 && (!found)){
            exit_pos=j;
            found=1;
        }
    }
    if (!found){
        printf("Warning: exit point not found.");
        return 2;
    }
    found=0;
    fare+=tolls[entry_pos];
    if (strcmp(checkpoint2[entry_pos], exit) == 0){
        printf("Destination reached in 1 section. Total fare: %.2f euros",fare);
        found=1;
    }
    else{
        fare+=tolls[exit_pos];
        strcpy(section2,checkpoint1[exit_pos]);
        if (strcmp(section2, checkpoint2[entry_pos]) == 0){
            printf("Destination reached in 2 sections. Total fare: %.2f euros.",fare);
            found=1;
        }
        else{
            for (j=0;j<i;j++) {
                if (strcmp(checkpoint1[exit_pos], section2) == 0)
                    medium_pos=j;
            }
            if (medium_pos==-1){
                printf("Warning: impossible to reach destination in a max of 3 sections.");
                return 3;
            }
            strcpy(section3, checkpoint1[medium_pos]);
            if (strcmp(checkpoint2[entry_pos], section3) == 0){
                fare+=tolls[medium_pos];
                printf("Destination reached in 3 sections. Total fare: %.2f euros.",fare);
                found=1;
            }
        }
    }
    if (!found){
        printf("Warning: impossible to reach destination in a max of 3 sections.");
        return 3;
    }
    return 0;
}