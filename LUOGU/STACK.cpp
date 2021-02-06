#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
  long long stack[1000]={0};
  long long i = 0, current = 0;
  char temp = getchar();
  while (temp != '@')
  {
    if (temp >= '0' && temp <= '9')
      {
        current *= 10;
        current += temp - '0'; 
      }
    else if (temp == '.')
    {
      i++;
      stack[i] = current;
      current=0;
    }
    else if (temp=='+')
    {
      stack[i-1]+=stack[i];
      stack[i]=0;
      i--;
    }
    else if(temp=='-')
    {
      stack[i-1]-=stack[i];
      stack[i]=0;
      i--;
    }
    else if(temp=='*')
    {
      stack[i-1]*=stack[i];
      stack[i]=0;
      i--;
    }
    else if(temp=='/')
    {
      stack[i-1]/=stack[i];
      stack[i]=0;
      i--;
    }
    temp=getchar();
  }
  cout<<stack[1];
  system("pause");
  return 0;
}