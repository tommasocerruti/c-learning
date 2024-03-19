#include <stdio.h>
#include <ctype.h>
#define INPUT "../input.txt"
#define OUTPUT "../output.txt"

int main() {
    FILE *fin, *fout;
    int i=0,end_flag,spa,newline_flag,maiusc_flag=0,line=0;
    char c_now,c_bef;
    if ((fin=fopen(INPUT,"r"))==NULL) {
        printf("INPUT FILE ERROR");
        return 1;
    }
    if ((fout=fopen(OUTPUT,"w"))==NULL) {
        printf("OUTPUT FILE ERROR");
        return 2;
    }
    fscanf(fin,"%c",&c_bef);
    while (!feof(fin)){
        end_flag=0;
        while (!feof(fin) && i<26 && end_flag == 0) {
            fscanf(fin,"%c",&c_now);
            if (newline_flag){
                i+=1;
                if (maiusc_flag){
                    c_bef= toupper(c_bef);
                    maiusc_flag=0;
                }
                newline_flag=0;
            }
            i +=1;
            if (c_bef=='\n'){
                spa=26-i;
                while (spa>0) {
                    fprintf(fout," ");
                    spa-=1;
                }
                i-=1;
                end_flag=1;
                newline_flag=1;
            }
            else if (i==26) {
                if (isdigit(c_bef))
                    c_bef='*';
                fprintf(fout,"%c",c_bef);
                i-=1;
                end_flag=1;
            }
            else if (c_bef==','||c_bef==';'||c_bef==':'||c_bef=='.'||c_bef=='!'||c_bef=='?'||c_bef=='\''||c_bef=='('||c_bef==')'){
                fprintf(fout,"%c",c_bef);
                if (c_now!=',' && c_now!=';' && c_now!=':' && c_now!='.' && c_now!='!' && c_now!='?' && c_now!='\''&& c_now!=' '&& c_now!='\n' && c_now!='(' && c_now!=')'){
                    fprintf(fout," ");
                    i+=1;
                }
                if (c_bef=='.'||c_bef=='!'||c_bef=='?'&&islower(c_now)){
                    if (c_now!='\n')
                        c_now= toupper(c_now);
                    else
                        maiusc_flag=1;
                }

            }
            else if (isdigit(c_bef))
                fprintf(fout,"*");
            else
                fprintf(fout,"%c",c_bef);
            c_bef=c_now;
        }
        if (feof(fin)){
            spa=25-i;
            while (spa>0) {
                fprintf(fout," ");
                spa-=1;
            }
        }
        if (!line && i<25){ // in case the first line is less than 25 chars long
            i-=1;
            fprintf(fout," ");
        }
        fprintf(fout,"| c:%d\n",i);
        i=0;
        line=1;
        c_bef=c_now;
    }
    fclose(fin);
    fclose(fout);
    return 0;
}