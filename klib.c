#include <stdio.h>
#include "klib.h"

int nascii(char n)
{
  if(n >= '0' && n <= '9')
    return (int) n-'0';
  else
    return (int) n+'0';
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
  ret= num[0]=='-'? -ret: ret;
  return ret;
}

long double deci(const char* num)
{
  int x= 0;
  long val= unint(num);
  long double ret= val >= 0? val: -val;
  while(num[x]!='\0')
    {
      if(num[x]=='.')
	{
	  while(ret > 1)
	    ret*= .1;
	  while(ret < pot(10,x-1))
	    ret*= 10;
	  if(num[0]=='-')
	  ret*=.1;
	}
      ++x;
    }
  ret= num[0]=='-'? -ret: ret;
  return ret;
}

unsigned long binario(unsigned long num)
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

unsigned int match(const char* str, char n)
{
  unsigned int ret= 0;
  int x= strl(str);
  while(x--)
      if(str[x]==n)
	++ret;
  return ret;
}

void copia(char* uno, char* due)
{
  int x= 0;
  while(x <= strl(uno))
    {
      due[x]= uno[x];
      ++x;
    }
}

void scambia(char* uno, char* due)
{
  int x= 0;
  char temp;
  while(x <= strl(uno))
    {
      temp= due[x];
      due[x]= uno[x];
      uno[x]= temp;
      ++x;
    }
}
