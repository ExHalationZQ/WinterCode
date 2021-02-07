#include <iostream>
using namespace std;
int s[10001];
int n, m;
int z, x, y;
int find(int k);
int main()
{
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    s[i] = i;
  for (int i = 1; i <= m; i++)
  {
    cin >> z >> x >> y;
    if (z == 1)
      s[find(x)] = find(y);
    else if (z == 2)
      if (find(x) == find(y))
        cout << 'Y' << endl;
      else
        cout << 'N' << endl;
  }
  system("pause");
  return 0;
}
int find(int k)
{
  if (s[k] == k)
    return k;
  else
    return s[k] = find(s[k]);
}