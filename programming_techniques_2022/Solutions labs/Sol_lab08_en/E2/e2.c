#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

#define SIZE 16
#define INPUT 0

/*
intero 1 su 32 bit (4 byte)

LITTLE ENDIAN: least significant byte to the lower address

       higher memory
          ----->
    +----+----+----+----+
    |0x01|0x00|0x00|0x00|
    +----+----+----+----+
    x
    |
   &x

BIG ENDIAN: most singificant byte to the lower address

    +----+----+----+----+
    |0x00|0x00|0x00|0x01|
    +----+----+----+----+
    x
    |
   &x

*/

/* choose the encoding function to use */
#define printEncoding printEncoding2
/* choose function to split bits */
#define splitBits splitBits3

void printEncoding1 (void *p, int size, int bigEndian);
void printEncoding2 (void *p, int size, int bigEndian);
void printMemory (void *p, int size, int bigEndian);
int checkBigEndian(void);

int main(int argc, char *argv[]) {

  float af;
  double ad;
  long double ald;

  int bigEndian = checkBigEndian();
  printf ("The system is: %s ENDIAN\n", bigEndian ? "BIG":"LITTLE");

  printf("Dimensions\n af = %d\n ad = %d\nald = %d\n",
	 (int)sizeof(af), (int)sizeof(ad), (int)sizeof(ald));

  printf("Insert a value (compatibile with float, double e long double): ");
  scanf("%f", &af);
  printf("Read: %f\n", af);

  ad = (double)af;
  ald = (long double)af;

  printf("\nprint float encoding:\n");
  /* printMemory is redundant (not required, but useful to 'see' the bits) */
  printMemory((void *)&af,sizeof(af),bigEndian);
  printEncoding((void *)&af,sizeof(af),bigEndian);

  printf("\nprint double encoding:\n");
  /* printMemory is redundant (not required, but useful to 'see' the bits) */
  printMemory((void *)&ad, sizeof(ad), bigEndian);
  printEncoding((void *)&ad,sizeof(ad),bigEndian);

  printf("\nprint long double encoding:\n");
  /* printMemory is redundant (not required, but useful to 'see' the bits) */
  printMemory((void *)&ald, sizeof(ald), bigEndian);
  printEncoding((void *)&ald,sizeof(ald),bigEndian);

  return 0;
}

int checkBigEndian(void) {
  int test = 1; /* only least significant byte !=0, all others ==0 */
  char *pchar = (char *)&test; /* points to the byte at the lowest address */
  /* chech byte at the lowest address: if ==0 Big Endian */
  return (*pchar == 0); /* pointers sintax */
  /* return (pchar[0] == 0); */ /* alternative array sintax */
}

void printMemory (void *p, int size, int bigEndian) {
  int i, j;

  /* unsigned to see bytes as numbers from 0 to 255 (FF) */
  /* pointer used as array of unsigned char */
  unsigned char *pchar = (unsigned char *)p;

  printf("print bytes in exadecimal (address: content)\n");
  for (i=0; i<size; i++) {
    printf("%p: %02x\n", &pchar[i], pchar[i]); /* %02x to write always 2 digits */
  }

  printf("print bytes from the most significant (left) to the least significant (right):\n");
  for (i=0; i<size; i++) {
    j = bigEndian ? i : size-1-i;
    printf("%02x", pchar[j]); /* %02x to write always 2 digits */
  }
  printf("\n");
}

/* detects bits from the least significant and it stores them in the char array (0/1)
starting with the cell l; */
void splitBits1(unsigned char byte, char *bits, int l) {
  int i;
  for (i=0; i<8; i++, byte /= 2) {
    bits[l+i] = byte%2; /* even: 0, odd: 1 */
  }
}

/* detects bits from the least significant and it stores them in the char array (0/1)
starting with the cell l;
variant with >> (shift) to perform /2 and performs bitwise AND to read the least significant bit */

void splitBits2(unsigned char byte, char *bits, int l) {
  int i;

  /* divide byts by 2 by shifting to 1 position to the right */
  for (i=0; i<8; i++, byte = byte>>1) {
    /* bitwise AND with mask 00000001, to isolate the least significant bit */
    bits[l+i] = byte & 0x01;
  }
}

/* detects bits from the least significant and it stores them in the char array (0/1)
starting with the cell l;
variant not moving bits in "byte", but "looks" at them through a filter:
a mask to be used to perform bitwise AND to highlight the chosen bit */
void splitBits3(unsigned char byte, char *bits, int l) {
  int i;
  unsigned char mask;
  /* divide byts by 2 by shifting to 1 position to the right */
  for (i=0,mask=0x01; i<8; i++, mask=mask<<1) {
    /* bitwise AND with mask, to isolate the least significant bit */
    bits[l + i] = byte & mask ? 1 : 0;
  }
}


int nBitExponent(int size) {
  switch (size) {
  case 4: return 8;   /* float */
  case 8: return 11;  /* double */
  default: return 15; /* long double */
  }
  return 0; /* error */
}

int dimensionwithPadding (int size, int bigEndian) {
  /* if long double and little endian */
  /* check padding if present (alignment) and decreases size */
  if (size>8 && !bigEndian) {
    int size1;
    /* puts into a and b two numbers which differ only by the sign */
    long double a = 1.0, b = -a;
    unsigned char *pa=(unsigned char *)&a, *pb=(unsigned char *)&b; /* pointers to bytes of a and b */
    /* assumes padding at high addresses and looks for bytes with sign bit */
    for (size1=0; size1<size && pa[size1]==pb[size1]; size1++);
    if (size1<size) {
      printf("Padding of %d byte(s)\n", size-size1-1);
      size = size1+1;
      printf("Dimensions (also including padding): %d\n", size);
    }
  }
  return size;
}

void printEncoding1 (void *p, int size, int bigEndian) {
  int i, nExpBits, nBits;
  unsigned char *pchar = p;
  char bits[128]; /* unsigned not needed, since it can be only 0/1 */

  size = dimensionwithPadding (size, bigEndian);

  /* offloads on bits variable the bits starting from the least singificant */
  for (i=0; i<size; i++) {
    splitBits(pchar[i], bits, i*8);
  }

  nBits = size*8;
  nExpBits = nBitExponent(size);

  printf("sign bit : %d\n", (int)bits[nBits-1]);
  printf("Exponent    : ");
  for (i=nBits-2; i>nBits-2-nExpBits; i--)
    printf("%d", (int)bits[i]);
  printf("\nmantissa     : ");
  for (i=nBits-2-nExpBits; i>=0; i--)
    printf("%d", (int)bits[i]);
  printf("\n");

}

int extractBit(unsigned char *bytes, int iBit) {
  int iByte = iBit/8; /* byte index= bit index/8 */

  unsigned char mask = 0x01 << (iBit%8); /* puts 1 in the desired position inside the byte */
  int bit = ((bytes[iByte] & mask) == 0) ? 0 : 1;

  return bit;
}

/* variant not using the ancilla bit array */
void printEncoding2 (void *p, int size, int bigEndian) {
  int i, nExpBits, nBits;
  unsigned char *pchar = p;

  size = dimensionwithPadding (size, bigEndian);

  nBits = size*8;
  nExpBits = nBitExponent(size);

  printf("sign bit : %d\n", extractBit(pchar,nBits-1));
  printf("Exponent    : ");
  for (i=nBits-2; i>nBits-2-nExpBits; i--)
    printf("%d", extractBit(pchar,i));
  printf("\nmantissa     : ");
  for (i=nBits-2-nExpBits; i>=0; i--)
    printf("%d", extractBit(pchar,i));
  printf("\n");

}
