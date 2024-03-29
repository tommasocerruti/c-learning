#ifndef _DATA_INCLUDED
#define _DATA_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXC 20

typedef struct data_s{
    char registerNumber[10];
    char *lastName;
    int numberCreditLoaded, numberCreditPassed;
}data_t;

int readData (FILE *, data_t *);
void writeData (FILE *, data_t);
int compare (data_t, data_t);

#endif
