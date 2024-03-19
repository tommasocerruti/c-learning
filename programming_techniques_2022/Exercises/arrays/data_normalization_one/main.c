#include <stdio.h>
#define MAX 100

void normalize (char f_in[], char f_out[]);
int read_file (char file_name[],float data[],int max_num);
void write_file (char file_name[],int data[],int num);
float average(float d[], int i0, int i1);

int main(void){ // running the program
    char f_in[20],f_out[20];
    scanf("%s%s",&f_in,&f_out);
    normalize(f_in,f_out);
    return 0;
}

void normalize (char f_in[], char f_out[]){ // program
    float data[MAX], data_new[MAX], pred, succ;
    int i, N;
    N = read_file(f_in,data,MAX); // reading from file;
    for (i=0;i<N;i++){
        pred= average(data,0,i-1); // average before i
        succ= average(data, i+1,N-1); // average after i
        data_new[i]= (pred+succ+data[i])/3; // average of the three values
    }
    write_file(f_out,data_new,N); // writing to file
}

int read_file (char file_name[],float data[],int max_num){ // reading from file
    FILE *fp;
    int i=0;
    fp=fopen(file_name,"r");
    if (fp==NULL)
        return i;
    while (i<max_num && fscanf(fp,"%f",&data[i])!=EOF)
        i++;
    fclose(fp);
    return i;
}
void write_file (char file_name[],int data[],int num) { // writing to file
    FILE *fp;
    int i;
    fp=fopen(file_name,"w");
    for (i=0;i<=num;i++)
        fprintf(fp,"%f",data[i]);
    fclose(fp);
}

float average(float d[], int i0, int i1){ // computing average
    int i;
    float sum=0.0;
    if (i0>i1) // no data
        return sum;
    for (i=i0;i<=i1;i++){ // valid data
        sum += d[i];
    }
    return sum/((float)(i1-i0+1));
}