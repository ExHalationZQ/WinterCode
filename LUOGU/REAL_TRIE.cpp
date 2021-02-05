#include <cstring>
#include <iostream>
using namespace std;
int label = 0, tr[1000001][26];
bool isward[1000001];
char word[1000001];
void insert()
{
  long long current = 0, len = strlen(word + 1);
  for (int i = 1; i <= len; i++)
  {
    int temp = word[i] - 'a';
    if (!tr[current][temp])
    {
      label++;
      tr[current][temp] = label;
    }
    current = tr[current][temp];
  }
  isward[current] = true;
}
int check()
{
  long long current = 0, len = strlen(word + 1); //同上
  for (int i = 1; i <= len; i++)
  {
    int temp = word[i] - 'a';
    if (!tr[current][temp])
      return -1;
    current = tr[current][temp];
  }
  if (isward[current] == true)
  {
    isward[current] = false; 
    return 1;
  }
  return 0;
}
int main()
{
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++)
  {
    cin>>word+1;
    insert();
  }
  int m;
  cin>>m;
  for (int i = 1; i <= m; i++)
  {
    cin>>word+1;
    int judge = check();
    if (judge == -1)
      cout<<"WRONG";
    else if (judge == 0)
      cout<<"REPEAT";
    else
      cout<<"OK";
    cout<<endl;
  }
  return 0;
}