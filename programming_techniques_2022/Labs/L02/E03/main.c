#include <stdio.h>
#include <ctype.h>
int compressing(FILE *fin, FILE *fout);
int decompressing(FILE *fin, FILE *fout);

int main(){
    char choice;
    int value;
    FILE *fin,*fout;
    printf("If you want to compress/decompress the file type C/D: ");
    scanf("%c",&choice);
    if (toupper(choice)=='C'){
        if ((fin=fopen("../source.txt", "r"))==NULL) {
            printf("Error opening input file (SOURCE.TXT)\n");
            return 0;
        }
        if ((fout=fopen("../compressed.txt", "w"))==NULL) {
            printf("Error opening output file (COMPRESSED.TXT)\n");
            return 0;
        }
        value = compressing(fin, fout);
    }
    else if (toupper(choice)=='D'){
        if ((fin=fopen("../compressed.txt", "r"))==NULL) {
            printf("Error opening input file (COMPRESSED.TXT)\n");
            return 0;
        }
        if ((fout=fopen("../source.txt", "w"))==NULL) {
            printf("Error opening output file (SOURCE.TXT)\n");
            return 0;
        }
        value = decompressing(fin, fout);
    }
    else{
        printf("Invalid operation");
        return 0;
    }
    fclose(fin);
    fclose(fout);
    return value;
}

int compressing(FILE *fin, FILE *fout) {
    char c1,c2;
    int i,end_flag,num=0;
    fscanf(fin,"%c",&c1); //first character
    while (!feof(fin)){
        end_flag=0;
        fscanf(fin,"%c",&c2);
        if (c1==c2) {
            i=0;
            while (!feof(fin)&&c1==c2){
                i+=1;
                fscanf(fin,"%c",&c2);
            }
            if (i==1){
                fprintf(fout,"%c%c",c1,c1);
                num+=2;
            }

            else if (i>=2&&i<10){
                fprintf(fout,"%c$%d",c1,i);
                num+=3;
            }
            else if (i>=10){
                fprintf(fout,"%c$%d",c1,9);
                num+=3;
                while (!end_flag){ //we want to split the count more than once if needed
                    i-=10; //not 9 because repetitions don't count the first instance
                    if (i==0)
                        end_flag=1;
                    else if (i<=2){
                        fprintf(fout,"%c%c",c1,c1);
                        end_flag=1;
                        num+=2;
                    }
                    else if (i>=2&&i<10){
                        fprintf(fout,"%c$%d",c1,i);
                        end_flag=1;
                        num+=3;
                    }
                    else if (i>=10){
                        fprintf(fout,"%c$%d",c1,9);
                        num+=3;
                    }
                }
            }
        }
        else{
            fprintf(fout,"%c",c1);
            num+=1;
        }
        c1=c2;
    }
    return num;
}

int decompressing(FILE *fin, FILE *fout) {
    char c1,c2,c3;
    int reps,num=0;
    fscanf(fin,"%c",&c1); //first character
    fscanf(fin,"%c",&c2); //second character
    while (!feof(fin)){
        fscanf(fin,"%c",&c3); //third character
        if (c2=='$'){
            reps=c3-'0'+1;
            num+=reps;
            while (reps>0){
                fprintf(fout,"%c",c1);
                reps-=1;
            }
            fscanf(fin,"%c",&c1);
            fscanf(fin,"%c",&c2);
        }
        else{
            fprintf(fout,"%c",c1); //
            num+=1;
            c1=c2;
            c2=c3;
        }
    }
    return num;
}