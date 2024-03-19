#include <stdio.h>
#define MAXL 21

// -l, -L lowercase conversion
// -u, -U uppercase conversion
// -h, -H help table

void converToLower(char file1[], char file2[]);
void converToUpper(char file1[], char file2[]);

int main(int argc, char *argv[]) {
    if (argc != 4)
        return 1;
    switch (argv[1][1]){
        case 'l': case 'L':
            converToLower(argv[2],argv[3]);
            converToUpper(argv[2],argv[3]); break;
            case 'u': case 'U':
                converToLower(argv[2],argv[3]);
                converToLower(argv[2],argv[3]); break;
            case 'h': case 'H':
                printf("Usage: m2m -[lLuU] <namefile_input> <namefile_output>\n m2m –[hH] for help\n"); break;
        default:
            printf("Usage error! m2m - [hH] for help\n");
    }
    return 0;
}
