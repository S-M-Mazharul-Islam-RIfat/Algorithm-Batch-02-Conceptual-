/**
* author: mj_riffu
* created: 2023-03-22 23:38:22
**/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;
vector<int> adj_list[maxN];
vector<bool> visited(maxN);
void dfs(int src)
{
    visited[src] = true;
    for (auto child : adj_list[src])
        if (!visited[child])
            dfs(child);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    vector<int> ans;
    for (int i = 1;i <= n;i++)
    {
        if (!visited[i])
        {
            ans.push_back(i);
            dfs(i);
        }
    }
    if (ans.size() <= 1)
        cout << 0 << '\n';
    else
    {
        vector<pair<int, int>> roads;
        for (int i = 0;i < ans.size() - 1;i++)
            roads.push_back({ ans[i],ans[i + 1] });
        cout << roads.size() << '\n';
        for (auto val : roads)
            cout << val.first << " " << val.second << '\n';
    }
    return 0;
}