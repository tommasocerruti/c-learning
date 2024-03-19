#include <stdio.h>
#define MAX_LENGTH 50

int main() {
    FILE *fp_in,*fp_out;
    char s0[MAX_LENGTH],s1[MAX_LENGTH];
    int ne=0, nmin;
    float score, avg=0, avg_min;
    printf("File input:"); scanf("%s",s0);
    printf("File output:"); scanf("%s",s1);
    fp_in = fopen(s0, "r"); fp_out = fopen(s1,"w");
    fprintf(fp_out,"STUDENTS QUALIFIED of the file %s\n",s0);
    printf("thresholds min. n. exams and avg score:");
    scanf("%d%f", &nmin, &avg_min);
    while (fgets(s0,MAX_LENGTH,fp_in)!=NULL){ //student id
        fgets(s1,MAX_LENGTH,fp_in); //name and surname
        while (fscanf(fp_in,"%f",&score)==1){
            avg+=score; ne++;
        }
        avg=avg/ne;
        if (avg>=avg_min && ne>=nmin) //condition
            fprintf(fp_out,"%s%s",s0,s1);
        avg=0; //reset
        ne=0; //reset
    }
    fclose(fp_in); fclose(fp_out);
    return 0;
}
