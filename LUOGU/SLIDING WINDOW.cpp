#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int n, k;
int a[1000001], q1[1000001], q2[1000001];
void min_que(void);
void max_que(void);
int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  min_que();
  cout<<endl;
  max_que();
  system("pause");
  return 0;
}
void min_que(void)
{
  int head = 1, tail = 0;
  for (int i = 1; i <= n; i++)
  {
    while (head <= tail && q1[head] + k <= i)
      head++;
    while (head <= tail && a[q1[tail]] > a[i])
      tail--;
    tail++;
    q1[tail] = i;
    if (i >= k)
      cout << a[q1[head]] << ' ';
  }
}
void max_que(void)
{
  int head = 1, tail = 0;
  for (int i = 1; i <= n; i++)
  {
    while (head <= tail && q2[head] + k <= i)
      head++;
    while (head <= tail && a[q2[tail]] < a[i])
      tail--;
    tail++;
    q2[tail] = i;
    if (i >= k)
      cout << a[q2[head]] << ' ';
  }
}