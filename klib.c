#include <stdio.h>
#include "klib.h"

int nascii(char n)
{
  if(n > 47 && n < 58)
    return (int) n-48;
  else
    return (int) n+48;
}

int qualcosa(int arg, char* cosa, char* nome)
{
  if(arg<=0)
    {
      printf("Inserire: %s dopo \"%s \"\n",cosa ,nome);
      return 1;
    } 
  else
    return 0;
}

long pot(long x, int y)
{
  if(y==0)
    return 1;
  else
    return x*pot(x,y-1);
}

long unit(int* num, int cifre)
{
  long ret=0;
  for(int x=0; x < cifre; x++)
    ret+= pot(10,x)*num[cifre-x-1];
  return ret;
}

long deci(char* num, int cifre)
{
  long ret=0;
  for(int x=0; x < cifre; x++)
    ret+= pot(10,x)*nascii(num[cifre-x-1]);
  return ret;
}

size_t strl(char* str)
{
  size_t ret = 0;
  while('\0' != str[ret])
      ret++;
  return ret;
}
