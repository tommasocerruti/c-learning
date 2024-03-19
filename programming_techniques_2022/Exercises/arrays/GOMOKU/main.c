#include <stdio.h>
#include <string.h>

#define MAXR 19
#define MAXC 19

/* Extended version with added functionalities (not requested by the text!)
 - the table can be even smaller than 19x19
 - the players can decide to terminate the game at any time, by providing 0,0 as the move
 - the user can specify the name of an output file where to print the final state of the table before terminating the game */

/* Differently from the previous version, a move is represented by a struct with three fields
 - two fields for the coordinates
 - a third field for a flag, indicating the request to terminate the game.
  --> Also the direction is represented by a struct with two fields (horizontal and vertical displacement) */

typedef struct move_s {
    int r;
    int c;
    int terminate;
} move_t;

typedef struct dir_s {
    int dx;
    int dy;
} dir_t;

move_t readMove(char t[MAXR][MAXC+1], char color, int nr, int nc);
int verifyMove(char t[MAXR][MAXC+1], move_t move, int nr, int nc);
int countInDirection(char t[MAXR][MAXC+1], move_t move, dir_t direction, int nr, int nc);
void printTable(FILE *fp, char t[MAXR][MAXC+1], int nr, int nc);

int main (void){
    char tab[MAXR][MAXC+1];
    char filename[30];
    move_t move;
    FILE *fp;
    int end=0, nr=0, nc;

    /* read matrix one line (string) at a time, counting the actual number of rows and columns */
    /* we accept matrixes smaller than 19x19, but we assume that all lines are of the same length */
    printf("Insert the name of the input file:");
    scanf("%s",filename);
    fp = fopen(filename,"r");
    while(fscanf(fp,"%s",tab[nr])!=EOF && nr<MAXR)
        nr++;  /* nr is the number of rows of the table */
    nc = strlen(tab[nr-1]); /* nc is the number of columns of the table */
    fclose(fp);

    while (!end) {
        printTable(stdout,tab,nr,nc);
        /* BLACK */
        move = readMove(tab,'B',nr,nc);
        if (move.terminate) // non-structured termination
            break;
        end = verifyMove(tab,move,nr,nc);
        if (end) {
            printf("black player is the winner!\n");
        }
        else {
            /* WHITE */
            move = readMove(tab,'W',nr,nc);
            if (move.terminate)   /* non-structured termination: as homework, modify to make it structured */
                break;
            end = verifyMove(tab,move,nr,nc);
            if (end) {
                printf("white player is the winner!\n");
            }
        }
    }

    printf("Insert the name of the output file:");
    scanf("%s",filename);
    fp = fopen(filename,"w");
    printTable(fp,tab,nr,nc);
    fclose(fp);
}

/* function that takes as parameter the table, the color of the current player and the dimensions of the table
 and asks the player (i.e., the user) to enter the next move (row and column) from keyboard.
 The function returns the entered move (move_t). In case the coordinates are both 0, the field terminate of the
 move is set to 1. As the move is a struct and not an array, it can be directly returned to the caller by a return */

move_t readMove(char t[MAXR][MAXC+1], char color, int nr, int nc){
    int r, c, ok;
    move_t m = {0,0,0};  /* Initializes all fields with 0 */
    do {
        if (color=='W')
            printf("Insert next move for white player:");
        else
            printf("Insert next move for black player:");
        scanf("%d%d",&r,&c);
        if (r==0 && c==0) {
            m.terminate = 1;
            return m;
        }
        r--; c--; /* user inserts coordinates in a 1 to 19 range..we need to have them in a 0 to 18 range*/
        if (r<0 || r>=nr || c<0 || c>=nc || t[r][c]!='.') {
            printf("Not valid: please insert another move\n");
            ok = 0;
        }
        else {
            t[r][c] = color;
            ok = 1;
        }
    } while (!ok);
    m.r = r;
    m.c = c;
    return m;
}

/* function that takes the current table, the move (type move_t) and a direction (type dir_t)
 as input parameters and counts the number of adjacent occupied boxes along the specified direction
 and starting from the input move. The count is returned to the caller. */

int countInDirection(char t[MAXR][MAXC+1], move_t move, dir_t direction, int nr, int nc) {
    int r, c, cnt, i, j, victory, dx, dy, col;
    r = move.r;
    c = move.c;
    col = t[r][c];
    /* displacement along rows and columns */
    dx = direction.dx;
    dy = direction.dy;
    /*boxes on the left" */
    for (i =r-dx,j=c-dy,cnt=1;
         i>=0 && j>=0 && i<nr && j<nc && t[i][j]==col;
         i-=dx,j-=dy)
        cnt++;
    /*boxes on the right */
    for (i =r+dx,j=c+dy;
         i>=0 && j>=0 && i<nr && j<nc && t[i][j]==col;
         i+=dx,j+=dy)
        cnt++;
    return cnt;
}

/* function that takes as parameters the table (and its dimensions) and the move (move_t type), and verifies
 if the current move leads to victory (by calling another function that counts the number of consecutive
 boxes of same color in the 4 different directions) and returns 1/0 flag, with 1 meaning victory
 The 4 directions are locally represented in the function by an array of dir_t (struct) elements, each
 representing the r,c displacement in one specific direction */

int verifyMove(char t[MAXR][MAXC+1], move_t move, int nr, int nc){
    int k, victory;
    dir_t delta[4] = {
            {0,1},
            {1,0},
            {1,1},
            {1,-1},
    };
    /* if none of the checks is verified, the flag remains 0 */
    victory = 0;
    /* k=0: row, k=1: column, k=2: diagonal, k=3: anti-diagonal */
    for (k=0; k<4 && !victory; k++)
        /* in C, a True statement (i.e., the result of the logic expression) is represented by a non-zero integer value */
        victory = (countInDirection(t, move, delta[k], nr, nc) >= 5);
    /* When victory is assigned a non-zero value, this is interpreted as a True. This ends the for loop */
    return victory;
}

/* print the table: takes as input parameters the pointer to the output file (already opened) and the table */
void printTable(FILE *fp, char t[MAXR][MAXC+1], int nr, int nc){
    int i, j;
    for (i=0; i<nr; i++) {
        for (j=0; j<nc; j++)
            fprintf(fp,"%c",t[i][j]);
        fprintf(fp,"\n");
    }
}