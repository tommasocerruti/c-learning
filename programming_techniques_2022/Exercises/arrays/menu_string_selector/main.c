// definition of constants and importing libs
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define c_seek 0
#define c_modify 1
#define c_print 2
#define c_end 3
#define c_err 4
const int MAX=51;

//definition of function
int read_command(void);
void menu_word(void);
void seek(char r[]) {printf("search: %s\n",r);}
void modify(char r[]) {printf("modify: %s\n",r);}
void print(char r[]) {printf("print: %s\n",r);}
void string_to_lower(char s[]) {
    int i, l= strlen(s);
    for (i=0;i<=l;i++)
        s[i]= tolower(s[i]);
}

//main function
int main() {
    menu_word();
    return 0;
}
void menu_word(void){
    int command;
    char line[MAX];
    int i, continue_flag=1;
    while (continue_flag) {
        command=read_command();
        fgets(line,MAX,stdin);
        switch (command) {
            case c_seek: seek(line); break;
            case c_modify: modify(line); break;
            case c_print: print(line); break;
            case c_end: continue_flag=0; break;
            case c_err:
            default: printf("wrong command\n");
        }
    }
}

int read_command(void){
    int c=c_seek;
    char cmd[MAX];
    char table[4][7]={
            "seek","modify","print","end"
    };
    printf("command (seek/modify/print/end):");
    scanf("%s",&cmd);
    string_to_lower(cmd);
    while (c<c_err && strcmp(cmd,table[c])!=0)
        c++;
    return c;
}