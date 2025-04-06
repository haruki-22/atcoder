#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n), rb(n);
  for (int i = 0; i < n; i++)
    cin >> a.at(i);
  for (int i = 0; i < n; i++)
    cin >> b.at(i);
  for (int i = 0; i < n; i++)
    rb.at(a.at(i) - 1) = b.at(i);

  vector<int> dp(n, 1e6);

  int j = 0;
  for (int i = 0; i < n; i++)
  {
    if (dp.at(j) < rb.at(i))
    {
      dp.at(j + 1) = rb.at(i);
      j++;
    }
    else
    {
      *upper_bound(dp.begin(), dp.end(), rb.at(i)) = rb.at(i);
    }
  }

  int ans = 0;
  while (ans < n && dp.at(ans) < 1e6)
    ans++;
  cout << n + ans;
}