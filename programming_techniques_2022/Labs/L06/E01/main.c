#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define FILENAME "../log.txt"
#define MAXL 1000
#define MAXC 31

typedef enum {
    c_date,c_departure,c_destination,c_delay,c_totdelay,c_end
} t_commands;

struct data{
    char code_route[MAXC],departure[MAXC],destination[MAXC];
    char date[11], time_departure[9], time_arrival[9];
    int delay;
};

void menu_word (struct data log[], int v);
t_commands readCommand(void);

void date(char begin[], char end[], struct data log[], int v); //1. list all rides departed within a certain interval of dates
void departure(char r[], struct data log[], int v); //2. list all the trips starting from a given departure
void destination(char r[], struct data log[], int v); //3. list all the trips starting from a given destination
void delay(char begin[], char end[], struct data log[], int v); //4. list all trips that reached their destination late, within a given interval of dates
void totdelay(char r[], struct data log[], int v); //5. list the overall delay accumulated by the trips that are identified by a given route code
//6. terminate the program (end)

void str_to_lower(char s[]) {
    int i, l = strlen(s);
    for (i=0; i<l; i++)
        s[i]=tolower(s[i]);
}

int main() {
    FILE *fp;
    int v,i;
    struct data log[MAXL];
    if ((fp=fopen(FILENAME,"r"))==NULL)
        return 1;
    fscanf(fp,"%d",&v);
    for (i=0;i<v;i++){
        fscanf(fp,"%s",log[i].code_route);
        fscanf(fp,"%s",log[i].departure);
        fscanf(fp,"%s",log[i].destination);
        fscanf(fp,"%s",log[i].date);
        fscanf(fp,"%s",log[i].time_departure);
        fscanf(fp,"%s",log[i].time_arrival);
        fscanf(fp,"%d",&log[i].delay);
    }
    menu_word(log,v);
    return 0;
}

void menu_word (struct data log[], int v){
    t_commands command;
    char line[MAXL],begin[MAXL],end[MAXL];
    int toContinue=1;
    while (toContinue) {
        command = readCommand();
        if (command!=c_end){
            if (command==c_date||command==c_delay)
                scanf("%s%s",begin,end);
            else
                scanf("%s",line);
        }

        switch (command) {
            case c_date: date(begin, end, log, v); break;
            case c_departure: departure(line, log, v); break;
            case c_destination: destination(line, log, v); break;
            case c_delay: delay(begin, end, log, v); break;
            case c_totdelay: totdelay(line, log, v); break;
            case c_end: toContinue=0; break;
            default: printf("Wrong command (type end to terminate)\n");
        }
    }
}

t_commands readCommand(void) {
    t_commands c;
    char cmd[MAXL];
    char table[6][12] = {
            "date","departure","destination","delay","totdelay","end"
    };
    printf("command (date/departure/destination");
    printf("/delay/totdelay/end):");
    scanf("%s",cmd);
    str_to_lower(cmd);
    c=c_date;
    while(strcmp(cmd,table[c])!=0)
        c++;
    return c;
}

void date(char begin[], char end[], struct data log[], int v){
    int i;
    for (i=0;i<v;i++){
        if (strcmp(begin,log[i].date)<=0 && strcmp(end,log[i].date)>=0)
            printf("%s %s\n",log[i].code_route,log[i].date);
    }
    printf("\n");
}

void departure(char r[], struct data log[], int v){
    int i;
    for (i=0;i<v;i++){
        if (strcmp(r,log[i].departure)==0)
            printf("Trip to %s the date %s\n",log[i].destination,log[i].date);
    }
    printf("\n");
}

void destination(char r[], struct data log[], int v){
    int i;
    for (i=0;i<v;i++){
        if (strcmp(r,log[i].destination)==0)
            printf("Trip from %s the date %s\n",log[i].departure,log[i].date);
    }
    printf("\n");
}

void delay(char begin[], char end[], struct data log[], int v){
    int i;
    for (i=0;i<v;i++){
        if (log[i].delay>0 && strcmp(begin,log[i].date)<=0 && strcmp(end,log[i].date)>=0)
            printf("%s was late of %d\n",log[i].code_route,log[i].delay);
    }
    printf("\n");
}

void totdelay(char r[], struct data log[], int v){
    int i, delay=0;
    for (i=0;i<v;i++){
        if (strcmp(r,log[i].code_route)==0)
            delay+=log[i].delay;
    }
    printf("Total delay is %d\n\n",delay);
}