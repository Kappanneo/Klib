#include <stdio.h>
#include "klib.h"

int qualcosa(const int arg, char* cosa, const char* nome)
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
  if(n >= '0' && n <= '9')
    return (int) n-48;
  else
    return (int) n+48;
}

double pot(double x, unsigned int y)
{
  if(!y)
    return 1;
  else
    return x*pot(x,y-1);
}

size_t strl(const char* str)
{
  size_t ret= 0;
  while(str[ret]!='\0')
    ++ret;
  return ret;
}

long unint(const char* num)
{
  int x= 0;
  long ret= 0;
  while(num[x]!='\0')
    {
      if(num[x] >= '0' && num[x] <= '9')
	{
	  ret*= 10;
	  ret+= nascii(num[x]);
	}
      ++x;
    }
  return ret;
}

long double deci(const char* num)
{
  int x= 0;
  long  double ret= unint(num);
  while(num[x]!='\0')
    {
      if(num[x]=='.')
	{
	  while(ret > 1)
	    ret*= .1;
	  while(ret < pot(10,x-1))
	    ret*= 10;
	}
      ++x;
    }
  return ret;
}

long binario(unsigned long num)
{
  long ret= 0;
  int x =0;
  while(num > 0)
    {
      ret+= pot(10,x)*(num%2);
      ++x;
      num/= 2;
    }
  return ret;
}
