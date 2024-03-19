#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "item.h"
#include "st.h"

int main () {
  Item item;
  Key k;
  int i, cont, maxN;

  fprintf (stdout, "Hash table size: ");
  scanf ("%d", &maxN);

  ST st = STinit(maxN);
  cont = 1;

  while(cont) {
    fprintf (stdout, "Operations (1:Insert, 2:Search, 3:Delete, 4:Display, 5:Exit): ");
    scanf("%d", &i);

    switch(i) {
       case 1:
	 fprintf (stdout, "  Enter item (name <space> value): ");
         item = ITEMscan();
         if (ITEMcheckvoid(STsearch(st, KEYget(item))))
           STinsert(st, item);
         break;
       case 2:
	 fprintf (stdout, "  Enter key: ");
         k = KEYscan();
         if (ITEMcheckvoid(STsearch(st, k)))
           fprintf (stdout, "  Data not found!\n");
         else
           fprintf (stdout, "  Data found!\n");
         break;
       case 3:
	 fprintf (stdout, "  Enter key: ");
         k = KEYscan();
         if (ITEMcheckvoid(STsearch(st, k)))
           fprintf (stdout, "  Data not found!\n");
         else
           STdelete(st, k);
         break;
       case 4:
	 STdisplay(st);
         break;
       case 5:
	 cont = 0;
         break;
       default:
	 fprintf (stdout, "  Invalid option\n");
	 break;
    }
  }
  
  return 0;
}
