#include <bits/stdc++.h>
using namespace std;

int bell(int n)
{
    vector<vector<int>> v(n);
    v[0].push_back(1);
    for (int i = 1; i < n; i++)
    {
        v[i].push_back(v[i - 1][i - 1]);
        for (int j = 0; j < i; j++)
        {
            v[i].push_back(v[i - 1][j] + v[i][j]);
        }
    }

    return v[n - 1][n - 1];
}