#ifndef _DATO_INCLUDED
#define _DATO_INCLUDED

#define MAXST 10

typedef struct item* Item;
typedef char *Key;

Item ITEMscan();
void ITEMshow(Item, FILE *);
int ITEMcheckvoid(Item);
Item ITEMsetvoid();
Key KEYscan();
int KEYcompare(Key, Key);
Key KEYget(Item);


Item ITEMset(char *, char *, int, int);

#endif

