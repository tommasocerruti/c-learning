// NOTE: we discussed in class that the readMatrix can avoid as argument maxR

#include <stdio.h>
#define NR 50
#define NC 50

typedef struct coordinates {
    int col_cord, row_cord;
} coord;

typedef struct region{
    coord pos;
    int height, width, area;
} reg;

void readMatrix(int m[][NC], int *nr, int *nc);
int detectRegion(int m[][NC], int *nr, int *nc, reg *max_height, reg *max_width, reg *max_area);

int main() {
    int nc,nr, m[NR][NC];
    reg max_height, max_width, max_area;
    readMatrix(m,&nr,&nc);
    if (detectRegion(m, &nr, &nc, &max_height, &max_width, &max_area)){
        printf("Max-height region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
               max_height.pos.row_cord,max_height.pos.col_cord,max_height.height,max_height.width,max_height.area);
        printf("Max-weight region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
               max_width.pos.row_cord,max_width.pos.col_cord,max_width.height,max_width.width,max_width.area);
        printf("Max-area region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
               max_area.pos.row_cord,max_area.pos.col_cord,max_area.height,max_area.width,max_area.area);
    }
    return 0;
}

void readMatrix(int m[][NC], int *nr, int *nc){
    FILE *fp;
    int i,j;
    fp=fopen("../matrix.txt","r");
    fscanf(fp,"%d %d",nr,nc);
    for (i=0;i<*nr;i++){
        for (j=0;j<*nc;j++)
            fscanf(fp,"%d",&m[i][j]);
    }
}

int detectRegion(int m[][NC], int *nr, int *nc, reg *max_height, reg *max_width, reg *max_area){
    int i=0,j=0,i_in,h=0,w=0,max_h=0,max_w=0,max_a=0,first=1,found;
    coord ref;
    while(i<*nr){
        while(j<*nc){
            if (m[i][j]==1){
                w+=1;
                if (first){
                    ref.col_cord=j;ref.row_cord=i;
                    first=0;
                }
            }
            if ((m[i][j]==0 || j==*nc-1) && w>0){
                i_in=ref.row_cord;
                if (j==*nc-1)
                    j++;
                while(i_in<*nr && m[i_in][j-1]==1){
                    h+=1;
                    i_in++;
                }
                if (h>max_h){
                    max_height->height=h;max_h=h;
                    max_height->width=w;
                    max_height->area=h*w;
                    max_height->pos=ref;
                    found=1;
                }
                if (w>max_w){
                    max_width->height=h;
                    max_width->width=w;max_w=w;
                    max_width->area=h*w;
                    max_width->pos=ref;
                    found=1;
                }
                if (h*w>max_a){
                    max_area->height=h;
                    max_area->width=w;
                    max_area->area=h*w;max_a=h*w;
                    max_area->pos=ref;
                    found=1;
                }
                first=1;w=0;h=0;
            }
            j++;
        }
        i++;
        j=0;
    }
    return found;
}