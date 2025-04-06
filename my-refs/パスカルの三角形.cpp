int n; // n次までのパスカルの三角形

vector<vector<int>> p(n + 1, vector<int>(1, 1));
if (n > 0)
  p.at(1).push_back(1);
for (int i = 2; i <= n; i++)
{
  for (int j = 0; j < i - 1; j++)
  {
    p.at(i).push_back(p.at(i - 1).at(j) + p.at(i - 1).at(j + 1));
  }
  p.at(i).push_back(1);
}

// 以上の計算量はO(N^2)

// 以下はO(N)のやり方

vector<ll> c(n + 1, 1);
for (int i = 1; i <= n; i++)
  c[i] = c[i - 1] * (n + 1 - i) / i;
