#include <stdio.h>
#include <math.h>
int verifyTemperature(FILE *fp);

int main(void){
    FILE *fp;
    fp=fopen("../temperature.txt","r");
    if (fp==NULL)
        return 2;
    else
        return verifyTemperature(fp);
}

int verifyTemperature(FILE *fp) {
    float t0,t1,t2;
    int verification=1;
    fscanf(fp,"%f%f",&t0,&t1);//0 1
    while(!feof(fp)){
        fscanf(fp,"%f",&t2);//2
        if (abs(t1-t0)>5 || abs(t2-t1)>5 || abs(t2-t0)>5)
            verification=0;
        t0=t1;
        t1=t2;
    }
    return verification;
}
