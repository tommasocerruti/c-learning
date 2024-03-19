#include "data.h"
#include <string.h>

int readData (FILE *fp, data_t *data){
    int valid;
    char registerNumber[10];
    char lastName[100];
    int numberCreditLoaded, numberCreditPassed;
    valid=fscanf(fp, "%s %s %d %d", registerNumber, lastName, &numberCreditPassed, &numberCreditLoaded);
    if (valid!=EOF){
        strcpy(data->registerNumber,registerNumber);
        data->lastName=strdup(lastName);
        data->numberCreditLoaded=numberCreditLoaded;
        data->numberCreditPassed=numberCreditPassed;
    }
    return valid;
}


void writeData (FILE *fp, data_t data){
  fprintf(fp, "%s %s %d %d\n", data.registerNumber, data.lastName, data.numberCreditPassed, data.numberCreditLoaded);
  return;
}

int compare (data_t d1, data_t d2){
  if (strcmp(d1.registerNumber,d2.registerNumber)<0) {
    return (-1);
  }
  else {
    if (strcmp(d1.registerNumber,d2.registerNumber)==0) {
      return (0);
    }
    else {
      return (1);
    }
  }
}