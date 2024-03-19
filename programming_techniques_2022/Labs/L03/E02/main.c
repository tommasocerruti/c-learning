#include <stdio.h>
#include <ctype.h>
#define INPUT_FILE "../expr.txt"

int main() {
    FILE *fin;
    char c1,c2;
    int error=0,num_line=1,num_par_op=0,num_par_cl=0,space=0,operation=0;
    if ((fin=fopen(INPUT_FILE,"r"))==NULL){
        printf("ERROR WITH INPUT_FILE");
        return 1;
    }
    fscanf(fin,"%c",&c1);
    while (!feof(fin)){
        while (c1!='\n' || !feof(fin)){
            fscanf(fin,"%c",&c2);
            if (isdigit(c1) || c1== '(' || c1== ')'|| c1== '+'|| c1== '-'|| c1== '/'|| c1== '*'|| c1== '%'|| c1== ' '){
                if (space && (c1==' '|| c2==')' || c2=='(') && isdigit(c2))
                    error=1;
                if ((isdigit(c1) && (c2==' ' || c2==')' || c2=='(')) || (space && (c2==' ' || c2==')' || c2=='(')))
                    space = 1;
                else // 2nd condition (if one or more spaces (including brackets) between numbers)
                    space=0; // && 3rd a condition (proper operands)
                if (c1=='(')
                    num_par_op += 1;
                else if (c2==')')
                    num_par_cl += 1;
                if (num_par_cl>num_par_op) // 1st a condition (brackets opened properly)
                    error=1;
                if (!isdigit(c2) && operation)
                    error=1; // 3rd b condition (proper operations)
                if (c1== '+'|| c1== '-'|| c1== '/'|| c1== '*'|| c1== '%'){
                    if (!isdigit(c2) && c2!=' ')
                        error=1;
                    else if (c2==' ')
                        operation=1;
                }
                else
                    operation=0;
            }
            else
                error=1;
            if (c1!='\n')
                c1=c2;
        }
        if (num_par_cl!=num_par_op) // 1st b condition (brackets balanced properly)
            error=1;
        if (error==1)
            printf("ERROR AT LINE %d",num_line);
        num_par_op=0;
        num_par_cl=0;
        space=0;
        operation=0;
        error=0;
        num_line+=1;
        c1=c2;
    }
    return 0;
}
