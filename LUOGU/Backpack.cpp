#include <iostream>
using namespace std;
int main()
{
  long long value[10010], time[10010], dp[100000];
  int t, m;
  cin >> t >> m;
  for (int i = 1; i <= m; i++)
    cin >> time[i] >> value[i];
  for (int i = 1; i <= m; i++)
  {
    for (int j = time[i]; j <= t; j++)
      dp[j] = max(dp[j], dp[j - time[i]] + value[i]);
  }
  cout << dp[t];
  system("pause");
  return 0;
}