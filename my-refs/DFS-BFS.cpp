#include <bits/stdc++.h>
using namespace std;

// 幅優先探索、深さ優先探索のメモ
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1, vector<int>(0));
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int terminal = 0;

    vector<int> answer(n + 1, 0);
    set<int> visited; // vector<bool> visited(n + 1, false);でも可
    visited.insert(terminal);
    stack<int> dfs; // 幅優先探索ならqueue<int> bfs;
    dfs.push(terminal);

    while (!dfs.empty())
    {
        int u = dfs.top();
        dfs.pop();
        for (int v : graph[u])
        {
            if (!visited.count(v))
            {
                visited.insert(v);
                tree.push_back(v);
                dfs.push(v);
            }
        }
    }
}