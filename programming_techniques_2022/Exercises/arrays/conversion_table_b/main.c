#include <string.h>
#include <stdio.h>

struct month_entry{
    int num;
    char name[10];
};

int read_table(struct month_entry t[]);
int month_string_to_num(struct month_entry table[], char month[]);

int main(void) {
    int num;
    char month[10];
    struct month_entry table[12];
    if (read_table(table))
        do {
            printf("write a month");
            scanf("%s",month);
            num=month_string_to_num(table, month);
            if (num>=0)
                printf("month: %s --> num: %d\n", month, num);
        } while (num>=0);
    return 0;
}

int read_table(struct month_entry table[]){
    FILE *fp;
    int i;
    fp=fopen("../table.txt","r");
    if (fp==NULL){
        printf("Error opening table.txt\n");
        return 0;
    }
    for (i=0;i<12;i++)
        fscanf(fp,"%d%s",&table[i].num,&table[i].name);
    return 1;
}

int month_string_to_num(struct month_entry table[], char month[]){
    int i;
    for (i=0;i<12;i++){
        if (strcmp(month,table[i].name)==0)
            return table[i].num;
    }
    return -1;
}