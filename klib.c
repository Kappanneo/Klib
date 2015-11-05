#include <stdio.h>
#include "klib.h"

int qualcosa(int arg, char* cosa, char* nome)
{
  if(arg<=0)
    {
      fprintf(stderr,"Inserire %s dopo \"%s \"\n",cosa?cosa:"qualcosa",nome);
      return 1;
    } 
  else
    return 0;
}

int nascii(char n)
{
  if(n > 47 && n < 58)
    return (int) n-48;
  else
    return (int) n+48;
}

long pot(long x, unsigned int y)
{
  if(!y)
    return 1;
  else
    return x*pot(x,y-1);
}

size_t strl(char* str)
{
  size_t ret= 0;
  while(str[ret]!='\0')
    ++ret;
  return ret;
}

long deci(char* num, size_t cif)
{
  if(!cif)
    return 0;
  else
    return nascii(num[cif-1])+10*deci(num,cif-1);
}
