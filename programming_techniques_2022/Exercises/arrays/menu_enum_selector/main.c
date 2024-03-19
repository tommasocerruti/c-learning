typedef enum {
c_seek,c_modify,c_print,c_end,c_err
} t_commands;
...
void menuWord (void){
t_commands command;
char line[MAXL];
int i, toContinue=1;
while (toContinue) {
command = readCommand();
fgets(line,MAXL,stdin); /* rest of the line*/
switch (command) {
case c_seek: seek(line); break;
...
}
}
}
t_commands readCommand(void) {
t_commands c;
char cmd[MAXL];
char table[4][7] = {
"seek","modify","print" "end"
};
printf("command (seek/modify");
printf("/print/end): ");
scanf("%s",cmd); strToLower(cmd);
c=c_seek;
while(c<c_err && strcmp(cmd,table[c])!=0)
c++;
return (c);
}
