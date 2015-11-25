#include <stdio.h>
#include "klib.h"

unsigned nascii(char n)
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
    return x*pot(x,--y);
}

unsigned long fatt(unsigned long x)
{
  if(!x)
    return 1;
  else
    return x*fatt(--x);
}

unsigned int strl(const char* str)
{
  unsigned int ret= 0;
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
      if(num[x]>='0' && num[x]<='9')
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
  long double ret= ABS(val);
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

void copia(const char* uno, char* due)
{
  int x= -1;
  while(++x <= strl(uno))
      due[x]= uno[x];
}

void scambia(char* uno, char* due)
{
  int x= -1;
  char temp;
  while(++x <= strl(uno))
    {
      temp= due[x];
      due[x]= uno[x];
      uno[x]= temp;
    }
}

void ordina(long double* num, unsigned int len)
{
  long double temp;
  while(--len)
    {
      int x= 0;
      while(len-x++)
	if(num[x] < num[x-1])
	  {
	    temp= num[x];
	    num[x]= num[x-1];
	    num[x-1]= temp;
	  }
    }
}

void charbin(long num, char* str, unsigned int len)
{
  while(len > 0)
    {
      str[len--]= (char) nascii(num%2);
      num/=2;
    }
}

unsigned int compara(char* uno, char* due)
{
  unsigned int match= 0;
  int x= 0;
  while(x < strl(uno))
    {
      if(uno[x]==due[x])
	match++;
      ++x;
    }
  return match;
}
