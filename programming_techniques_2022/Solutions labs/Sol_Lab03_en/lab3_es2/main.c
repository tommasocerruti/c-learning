#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp_in;
    char ch, ch_prec, ch_space;
    int flag_par, flag_space, flag, counter=1;

    if ((fp_in = fopen("../expr.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    flag_par = 0;
    flag_space = 0;
    ch_prec = '(';
    ch_space = '(';
    while(!feof(fp_in)){
        flag = 0;
        ch = fgetc(fp_in);
//        if (!feof(fp_in)){
            if (ch == '(')
                flag_par++;
            if (ch == ')')
                flag_par--;
            if(!(isdigit(ch) && isdigit(ch_space))){
                if (isdigit(ch) || ch == '('){
                    if(!(ch_prec == '(' || ch_prec == '+' || ch_prec == '*' || ch_prec == '-' || ch_prec == '/')){
                        printf("Error reading number (expression %d)\n", counter);
                        fscanf(fp_in,"%*[^\n]");
                        ch= fgetc(fp_in);
                        flag = 1;
                    }
                }

                if (ch == ')' || ch == '+' || ch == '*' || ch == '-' || ch == '/' || ch == '\n'){
                    if (!(ch_prec == ')' || isdigit(ch_prec))) {
                        printf("Error reading operand (expression %d)\n", counter);
                        if (ch != '\n'){
                            fscanf(fp_in,"%*[^\n]");
                            ch = fgetc(fp_in);
                        }
                        flag = 1;

                    }
                }
            }


            if (!isspace(ch)){
            ch_prec = ch;
            }

            ch_space = ch;

            if (ch == '\n' || ch == EOF){
                if (flag == 0 && flag_par != 0){
                    printf("Error reading operand (expression %d)\n", counter);
                }
                ch_prec = '(';
                ch_space = '(';
                flag_par = 0;
                counter++;
            }
//        }
	
    }
	fclose(fp_in);
    return 0;
}
