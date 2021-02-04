#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
char s1[1000000], s2[1000000];
int kmp[1000000];
int main()
{
  cin >> s1 >> s2;
  int len1 = strlen(s1), len2 = strlen(s2);
  int k = 0;
  kmp[1] = kmp[0] = 0;
  for (int i = 1; i < len2; i++)
  {
    while (s2[i] != s2[k] && k != 0)
      k = kmp[k];
    if(s2[i]==s2[k])
    {
      k++;
      kmp[i+1]=k;
    }
    else
    {
      kmp[i+1]=0;
    }
    
  }
  k = 0;
  for (int i = 0; i < len1; i++)
  {
    while (s1[i] != s2[k] && k != 0)
      k = kmp[k];
    if (s1[i] == s2[k])
      k += 1;
    if (k == len2)
      cout << i - len2 + 2 << endl;
  }
  for (int i = 1; i <= len2; i++)
    cout << kmp[i]<<" ";
  system("pause");
  return 0;
}