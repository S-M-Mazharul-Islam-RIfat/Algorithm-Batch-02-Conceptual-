/**
* author: mj_riffu
* created: 2023-03-22 22:07:48
**/
#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
vector<int> adj_list[maxN];
vector<bool> visited(maxN);
vector<int> color(maxN);
bool dfs(int node)
{
    visited[node] = true;
    for (int child : adj_list[node])
    {
        if (!visited[child])
        {
            if (color[node] == 1)
                color[child] = 2;
            else
                color[child] = 1;

            bool bicolor_able = dfs(child);
            if (!bicolor_able)
                return false;
        }
        else
        {
            if (color[node] == color[child])
                return false;
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodes, edges;
    cin >> nodes >> edges;
    for (int i = 1;i <= edges;i++)
    {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    bool ok = true;
    for (int i = 1;i <= nodes;i++)
    {
        if (!visited[i])
        {
            color[i] = 1;
            bool yes = dfs(i);
            if (!yes)
            {
                ok = false;
                break;
            }
        }
    }
    if (ok)
    {
        for (int i = 1;i <= nodes;i++)
            cout << color[i] << " ";
        cout << '\n';
    }
    else
        cout << "IMPOSSIBLE";
    return 0;
}