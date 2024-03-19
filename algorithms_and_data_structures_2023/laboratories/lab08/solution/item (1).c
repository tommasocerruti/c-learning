#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "item.h"

struct item {
  char *key;
  char *name;
  int ncl;
  int ncp;
};

Item ITEMscan() {
  char name[MAXST];
  int value;

  scanf ("%s%d", name, &value);

  Item tmp = (Item) malloc(sizeof(struct item));
  if (tmp == NULL)
    return ITEMsetvoid();

  else {
    tmp->name = strdup(name);
    tmp->ncl = value;
  }
  return tmp;
}

void ITEMshow(Item data, FILE *fp) {
  fprintf (fp, "%s %s %d %d\n",
    data->key, data->name, data->ncp, data->ncl);
}

int ITEMcheckvoid(Item data) {
  Key k1, k2="";
  k1 = KEYget(data);
  if (KEYcompare(k1,k2)==0)
    return 1;
  else
    return 0;
}

Item ITEMsetvoid() {
  char name[MAXST]="";
  Item tmp = (Item) malloc(sizeof(struct item));
  if (tmp != NULL) {
    tmp->key = strdup(name);
    tmp->name = NULL;
    tmp->ncl = -1;
    tmp->ncp = -1;
  }
  return tmp;
}

Item ITEMset (
  char *key,
  char *name,
  int ncl,
  int ncp
  )
{
  Item tmp = (Item) malloc(sizeof(struct item));
  if (tmp == NULL) {
    return ITEMsetvoid();
  } else {
    tmp->key = strdup(key);
    tmp->name = strdup(name);
    tmp->ncl = ncl;
    tmp->ncp = ncp;
  }
  return tmp;
}

Key KEYscan() {
  char name[MAXST];
  Key k;
  scanf("%s", name);
  k = strdup(name);
  return k;
}

int  KEYcompare(Key k1, Key k2) {
  return strcmp(k1,k2);
}

Key KEYget(Item data) {
  return data->key;
}
