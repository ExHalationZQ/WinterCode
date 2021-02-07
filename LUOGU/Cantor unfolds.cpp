#include <iostream>
using namespace std;
long long tree[1000001], fa[1000001],a[1000001];
const long long mod = 998244353;
long long n;
int lowbit(long long x)
{
  return x & -x;
}
void update(long long x,long long y)
{
	while(x<=n)
  {
		tree[x]+=y;
		x+=lowbit(x);	
	}
}
long long ask(long long x)
{
  long long sum=0;
  while(x!=0)
  {
    sum+=tree[x];
    x=x-lowbit(x);
  }
  return sum;
}
int main()
{
  cin >> n;
  fa[0]=1;
  for (int i = 1; i < n; i++)
  {
    fa[i] = i * fa[i - 1] % mod;
    update(i,1);
  }
  long long ans =0;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
    ans=(ans+(ask(a[i]-1)*fa[n-i])%mod)%mod;
    update(a[i],-1);
  }
  cout<<ans+1;
  system("pause");
  return 0;
}