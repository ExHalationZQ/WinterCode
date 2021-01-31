#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
struct Ma
{
  int m[100][100];
};
Ma Get_ma(void);
Ma Fast(Ma I);
void Print_Ma(Ma &M);
int n, k;
inline Ma operator*(const Ma &r, const Ma &l)
{
  Ma A;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
      {
        A.m[i][j] += r.m[i][k] * l.m[k][j];
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
  while (k != 0)
  {
    if (k % 2 == 1)
      A = A * I;
    I = I * I;
    k /= 2;
  }
  return A;
}
void Print_Ma(Ma &M)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << M.m[i][j] << ' ';
    cout << endl;
  }
}