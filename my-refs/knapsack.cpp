#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using ll = long long;

template <typename T>
using vv = vector<vector<T>>;
template <typename T>
using vvv = vector<vector<vector<T>>>;

/* 1種類の荷物を何個でも積んでいい時のナップザック法 */
int main()
{
    int n, W;
    cin >> n >> W;

    vector<ll> v(n), w(n), dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i] >> v[i];

    for (int i = 0; i < W; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ll k = 1;
            int total_weight = i + w[j] * k;

            while (total_weight <= W)
            {
                dp[total_weight] = max(dp[total_weight], dp[i] + v[j]);
                k++;
                total_weight = i + w[j] * k;
            }
        }
    }

    cout << *max_element(begin(dp), end(dp)) << endl;
}