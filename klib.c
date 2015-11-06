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
  if(n > 47 && n < 58)
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
      if(num[x] > 47 && num[x] < 58)
	{
	  ret*= 10;
	  ret+= nascii(num[x]);
	}
      ++x;
    }
  return ret;
}

double deci(const char* num)
{
  int x= 0;
  double ret= unint(num);
  while(num[x]!='\0')
    {
      if(num[x]=='.')
	{
	  while((int) ret > pot(10,x))
	    ret*= .1;
	}
      ++x;
    }
  return ret;
}
