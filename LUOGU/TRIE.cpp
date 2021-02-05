#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
map<string, int> z;
string s;
int n, m;
int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> s;
    z[s] = 1;
  }
  cin >> m;
  for (int i = 0; i < m; i++)
  {
    cin >> s;
    if (z[s] == 1)
    {
      cout << "OK" << endl;
      z[s] = -1;
    }
    else if (z[s] == -1)
      cout << "REPEAT" << endl;
    else
      cout << "WRONG"<<endl;
  }
  return 0;
}