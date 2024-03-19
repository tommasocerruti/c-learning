#include "data.h"

int
readData (
  FILE *fp,
  data_t *data
  )
{
  char *tmpData, row[MAXC];
  int retValue;

  retValue = fscanf (fp, "%s", row);

  tmpData = (char *) malloc ((strlen(row)+1) * sizeof (char));
  if (tmpData == NULL) {
    fprintf (stderr, "Allocation Error.\n");
    exit (1);
  }

  /* Get Rid of New-Line */
  strcpy (tmpData, row);
  *data = (data_t) tmpData;

  return (retValue);
}


void
writeData (
  FILE *fp,
  data_t data
  )
{
  fprintf(fp, "%s\n", data);

  return;
}


int
compare (
  data_t d1,
  data_t d2
  )
{
  return (strcmp(d1, d2));
}

