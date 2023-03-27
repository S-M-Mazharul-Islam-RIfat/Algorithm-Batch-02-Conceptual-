// problem link - https://cses.fi/problemset/task/1671/

/**
* author: mj_riffu
* created: 2023-03-27 23:36:55
**/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 1e5 + 5;
ll dist[maxN];
const ll inf = 9e18;
vector<pair<int, int>> adj[maxN];
vector<bool> visited(maxN);

void dijkstra(int s, int n)
{
    for (int i = 1;i <= n;i++)
        dist[i] = inf;
    dist[s] = 0;

    priority_queue< pair<ll, ll>, vector< pair<ll, ll> >, greater< pair<ll, ll>>> pq;
    pq.push({ 0,s });

    while (!pq.empty())
    {
        int u = pq.top().second;
        ll cost = pq.top().first;
        pq.pop();

        if (visited[u])
            continue;
        visited[u] = true;

        for (auto child : adj[u])
        {
            int v = child.first;
            ll c = child.second;
            if ((cost + c) < dist[v])
            {
                dist[v] = (cost + c);
                pq.push({ dist[v],v });
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v,w });
    }
    dijkstra(1, n);
    for (int i = 1;i <= n;i++)
        cout << dist[i] << " ";
    cout << '\n';
    return 0;
}