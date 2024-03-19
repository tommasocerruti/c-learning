#include <stdio.h>
#include <string.h>
#define N 15
#define D 7
typedef struct {char day[N]; int nbook; int count;} bookings;

int printReservations(FILE *fp) {
    bookings bookd[D];
    int i, num,  max=-1;
    float avg;
    char days[D][N]={"Lunedi","Martedi","Mercoledi","Giovedi","Venerdi","Sabato","Domenica"};
    char dayc[N];
    //initialize
    for (i=0;i<D;i++){
        bookd[i].nbook=0; bookd[i].count=0; strcpy(bookd[i].day,days[i]);
    }
    while (fscanf(fp,"%s %d",dayc,&num)==2){
        i=0;
        while (strcmp(dayc,days[i])!=0)
            i++;
        bookd[i].count++;bookd[i].nbook+=num;
    }
    for (i=0; i<D; i++){
        avg=(bookd[i].nbook/bookd[i].count);
        printf("%s: %d prenotazioni, %f clienti in media per turno\n",bookd[i].day,bookd[i].count,avg);
        if (bookd[i].nbook>max)
            max=bookd[i].nbook;
    }
    return max;
}
