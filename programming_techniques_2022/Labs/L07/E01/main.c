#include <stdio.h>
#define MAX 50

struct coord {
    int col_cord, row_cord;
};

struct region{
    struct coord pos;
    int height, width, area;
};

int main() {
    int nc,nr;
    int i,j,i_in,h=0,w=0,m[MAX][MAX];
    int max_h=0,max_w=0,max_a=0,first=1;
    struct coord ref;
    struct region max_height, max_width, max_area;
    FILE *fp;
    if ((fp=fopen("../matrix.txt","r"))==NULL)
        return 1;
    fscanf(fp,"%d %d",&nr,&nc);
    for (i=0;i<nr;i++){
        for (j=0;j<nc;j++)
            fscanf(fp,"%d",&m[i][j]);
    }
    i=0; j=0;
    while(i<nr){
        while(j<nc){
            if (m[i][j]==1){
                w+=1;
                if (first){
                    ref.col_cord=j;ref.row_cord=i;
                    first=0;
                }
            }
            if ((m[i][j]==0 || j==nc-1) && w>0){
                i_in=ref.row_cord;
                if (j==nc-1)
                    j++;
                while(i_in<nr && m[i_in][j-1]==1){
                    h+=1;
                    i_in++;
                }
                if (h>max_h){
                    max_height.height=h;max_h=h;
                    max_height.width=w;
                    max_height.area=h*w;
                    max_height.pos=ref;
                }
                if (w>max_w){
                    max_width.height=h;
                    max_width.width=w;max_w=w;
                    max_width.area=h*w;
                    max_width.pos=ref;
                }
                if (h*w>max_a){
                    max_area.height=h;
                    max_area.width=w;
                    max_area.area=h*w;max_a=h*w;
                    max_area.pos=ref;
                }
                first=1;w=0;h=0;
            }
            j++;
        }
        i++;
        j=0;
    }
    printf("Max-height region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           max_height.pos.row_cord,max_height.pos.col_cord,max_height.height,max_height.width,max_height.area);
    printf("Max-weight region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           max_width.pos.row_cord,max_width.pos.col_cord,max_width.height,max_width.width,max_width.area);
    printf("Max-area region: upper left corner=(%d,%d), height=%d, width=%d, area=%d\n",
           max_area.pos.row_cord,max_area.pos.col_cord,max_area.height,max_area.width,max_area.area);
    return 0;
}
