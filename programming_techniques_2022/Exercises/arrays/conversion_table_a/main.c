#include <string.h>

int month_to_string(char month[]) {
    char table[13][10] = {"","January","February","March","April","May","June",
                  "July","August","September","October","November","December"};
    int i;
    for (i=1;i<=12;i++){
        if (strcmp(month,table[i])==0){
            return i; //found month (return month)
        }
    }
    return -1; //not found month (return standard)
}