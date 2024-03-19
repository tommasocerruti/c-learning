#include <stdio.h>
#include <math.h>

#define MAXDATA 30

int repeatedData(FILE *fp);
int similar (float a, float b);


int main() {
    FILE *fp= fopen("../data.txt","r");
    return repeatedData(fp);
}

int repeatedData(FILE *fp) {
    float data[MAXDATA];
    int ndata, i, j, repeated=0;
    fscanf(fp,"%d",&ndata);
    for (i=0; i<ndata; i++)
        fscanf(fp,"%f",&data[i]);
    for (i=0; i<ndata; i++) {
        for (j=0; j<ndata && !repeated; j++)
            if (i!=j && similar(data[i],data[j]))
                repeated=1;
    }
    return repeated;
}

int similar (float a, float b) {
    if (fabs(a)>fabs(b))
        return (fabs(a-b)/fabs(a) < 0.01);
    else
        return (fabs(a-b)/fabs(b) < 0.01);
}