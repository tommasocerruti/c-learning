#include <stdio.h>
#include <string.h>
#include <ctype.h>

void seek(char row[]);
void modify(char row[]);
void print(char row[])

int main() {
    const int MAXL=51;
    char command[MAXL], row[MAXL];
    int i, toContinue=1;
    while (toContinue) {
        printf("command (seek/mod/pr/end):");
        scanf("%s", command); /* command */
        for (i=0; i<strlen(command); i++)
            command[i] = toupper(command[i]);
        gets(row); /* rest of the line */
        if (strcmp(command, "SEEK")==0) {
            seek(row);
        } else if (strcmp(command, "MOD")==0) {
            modify(row);
        } else if (strcmp(command, "PR")==0) {
            print(row);
        } else if (strcmp(command, "END")==0) {
            toContinue =0;
        } else {
            printf("non valid command\n");
        }
    }
    return 0;
}
}
