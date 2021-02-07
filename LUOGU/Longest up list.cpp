#include<iostream>
using namespace std;
int n,lis=0;
int a[100001],smallest[100001];
int main()
{
  cin>>n;
  for(int i=1;i<=n;i++)
  cin>>a[i];
  for(int i=1;i<n;i++)
  {
    if(a[i]>smallest[lis])
    {
      lis++;
      smallest[lis]=a[i];
    }
    else
    {
      for(int j=1;j<=lis;j++)
      {
        if(smallest[j]>a[i])//如3.7.8.4.5.6,到5的时候会自动覆盖掉8，保证当前时最优解
        {
          smallest[j]=a[i];
          break;
        }
      }
    }
  }
  cout<<n-lis<<endl;
  system("pause");
  return 0;
}
