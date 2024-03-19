#include <stdio.h>
#define LENGTH 10
void read_vector(int data[],int n);
void print_vector(int data[],int n);

int main() {
    int i,j,ni,found,data1[LENGTH],data2[LENGTH];
    read_vector(data1,LENGTH);
    read_vector(data2,LENGTH);
    // compare the vectors
    for (i=ni=0;i<LENGTH;i++){
        found=0;
        for (j=0;j<LENGTH && (!found);j++){
            if (data1[i]==data2[j]){
                found=1;
            }
        }
        if (found==1){
            data1[ni]=data1[i];
            ni++;
        }
    }
    print_vector(data1,ni);
    return ni;
}
void read_vector(int data[],int n){
    int i;
    printf("Enter first %d data (distinct and seperated by space or line):\n",n);
    for (i=0;i<n;i++)
        scanf("%d",&data[i]);
}
void print_vector(int data[],int n){
    int i;
    printf("There are %d shared values:\n",n);
    for (i=0;i<n;i++)
        printf("%d ",data[i]);
}