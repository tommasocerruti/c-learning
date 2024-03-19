#include "data.h"

char *
getField1 (
  data_t data
  )
{
  return (data->key);
}

char *
getField2 (
  data_t data
  )
{
  return (data->name);
}

int
getField3 (
  data_t data
  )
{
  return (data->ncl);
}

int
getField4 (
  data_t data
  )
{
  return (data->ncp);
}


int
readData (
  FILE *fp,
  data_t *data
  )
{
  char key[MAXC], name[MAXC];
  data_t tmpData;
  int ncl, ncp, retValue;

  tmpData = (data_t) malloc (1 * sizeof (struct data_s));
  if (tmpData == NULL) {
    fprintf (stderr, "Allocation Error.\n");
    exit (1);
  }

  retValue = fscanf (fp, "%s %s %d %d\n", key, name, &ncl, &ncp);
  if (retValue!=4) {
    return (retValue);
  }

  tmpData->key = malloc ((strlen (key) + 1) * sizeof (char));
  tmpData->name = malloc ((strlen (name) + 1) * sizeof (char));
  if (tmpData->key==NULL || tmpData->name==NULL) {
    fprintf (stderr, "Allocation Error.\n");
    exit (1);
  }
  strcpy (tmpData->key, key);
  strcpy (tmpData->name, name);
  tmpData->ncl = ncl;
  tmpData->ncp = ncp;

  *data = tmpData;

  return (retValue);
}

void
writeData (
  FILE *fp,
  data_t data
  )
{
  fprintf(fp, "%s %s %d %d\n",
    data->key, data->name, data->ncl, data->ncp);

  return;
}


int
compare (
  data_t d1,
  data_t d2
  )
{
  return (strcmp(d1->key, d2->key));
}

