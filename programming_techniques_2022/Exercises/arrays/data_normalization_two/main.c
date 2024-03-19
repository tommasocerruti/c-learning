#include <stdio.h>

#define MAX 100

void normalize(char f_in, char f_out);
int read_file(char f_in, float data[],int n);
void write_file(char f_out, float data_new[],int N);

void normalize(char nfin, char nfout) {
    float data[MAX], sum[MAX];
    int i, N, STOT;
/* input */
    N = read_file(nfin,data,MAX); /* input */
/* partial sums */
    sum[0]=data[0];
    for (i=1; i<N; i++)
        sum[i] = sum[i-1]+data[i];
    STOT = sum[N-1]; /* sum of all numbers */
/* normalize (0 and N-1 handled out of the loop)*/
    data[0] = (data[0] + (STOT-data[0])/(N-1))/3;
    for (i=1; i<N-1; i++) {
        float pred = sum[i-1]/i;
        float succ = (STOT-sum[i])/(N-i-1);
        data[i] = (pred+data[i]+succ)/3;
    }
    data[N-1] = (data[N-1] + sum[N-2]/(N-1))/3;
    write_file(nfout,data,N); /* output */
}

int read_file(char f_in, float data[], int n){
    FILE *fp;
    int i=0;
    fp= fopen(f_in,"r");
    if (fp==NULL)
        return i;
    while (i<n && fscanf(fp,"%f",&data[i])!=EOF)
        i++;
    fclose(fp);
    return i;
}

void write_file(char f_out, float data_new[], int N){
    FILE *fp;
    int i;
    fp= fopen(f_out,"w");
    for (i=0; i<N; i++)
        fprintf(fp,"%f",data_new[i]);
    fclose(fp);
}