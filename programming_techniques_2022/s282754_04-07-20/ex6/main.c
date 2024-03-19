#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 4
#define T 10

typedef struct{char id[N]; float val;} customer;

int analyseBill(FILE *fp, int *num) {
    int i, maxi, ind;
    num=0;
    float v, max=0; // assuming there is one customer with dept higher than 0
    customer customers[T];
    char idv[N];
    // initialize
    for (i=0;i<T;i++)
        customers[i].val=0;
    while (fscanf(fp,"%s %f",idv,&v)==2){
        // assuming clients are in the format C00N, where N is a number (I got the approval from the prof)
        ind=atoi(idv[3]);
        strcpy(customers[ind].id,idv);
        customers[ind].val+=v;
        if (customers[ind].val>max){
            max=customers[ind].val; maxi=ind;
        }
    }
    for (i=0; i<T; i++){
        if (strcmp(customers[i].id, NULL)!=0){
            printf("customer %S: %d\n",customers[i].id,customers[i].val);
            num+=1;
        }
    }
    printf("Customer with highest dept: %s, %f",customers[maxi].id,max);
    return num;
}
