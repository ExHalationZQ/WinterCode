#include <iostream>
using namespace std;
const int mod = 1000000007;
struct Ma
{
  long long m[100][100];
};
Ma Get_ma(void);
Ma Fast(Ma I);
void Print_Ma(Ma &M);
long long n, k;
inline Ma operator*(const Ma &l, const Ma &r)
{
  Ma A;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      A.m[i][j] = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
      {
        A.m[i][j] += l.m[i][k] * r.m[k][j]%mod;
        A.m[i][j] %= mod;
      }
  return A;
}
int main()
{
  cin >> n >> k;
  Ma I = Get_ma();
  Ma A = Fast(I);
  Print_Ma(A);
  system("pause");
  return 0;
}
Ma inline Get_ma(void)
{
  Ma I;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> I.m[i][j];
  return I;
}
Ma Fast(Ma I)
{
  Ma A;
  for (int i = 0; i < n; i++)
    A.m[i][i] = 1; //单位矩阵视为矩阵中的“1”；
  while (k > 0)
  {
    if (k % 2 == 1)
      A = A * I;
    I = I * I;
    k = k >> 1;
  }
  return A;
}
void Print_Ma(Ma &M)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << M.m[i][j]<< ' ';
    cout << endl;
  }
}