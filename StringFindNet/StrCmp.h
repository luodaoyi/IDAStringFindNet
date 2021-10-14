#include <string.h>
#include <stdio.h>

bool FindCmp(unsigned char* dsc, unsigned char* scr, int n);

int FindAscii(unsigned char* scr, int n,int pstrlen,int *pretlen,int *pisunicode);
int FindAsciiNext(unsigned char* scr, int n,int pstrlen,int ppos,int *pretlen,int *pisunicode);

int FindAsciiU(unsigned char* scr, int n,int pstrlen,int *pretlen);
int FindAsciiNextU(unsigned char* scr, int n,int pstrlen,int ppos,int *pretlen);

int FindAsciiUtf8(unsigned char* scr, int n,int pstrlen,int *pretlen);
int FindAsciiNextUtf8(unsigned char* scr, int n,int pstrlen,int ppos,int *pretlen);