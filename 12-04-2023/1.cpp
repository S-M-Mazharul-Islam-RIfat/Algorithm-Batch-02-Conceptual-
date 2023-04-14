// Problem Link -  https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/A
/**
* author: mj_riffu
* created: 2023-04-12 22:50:11
**/
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 10;
int _parent_[maxN], _rank_[maxN];

int _find_(int node)
{
    if (node == _parent_[node])
        return node;
    int x = _find_(_parent_[node]);
    _parent_[node] = x;
    return _parent_[node];
}
void _union_(int a, int b)
{
    a = _find_(a);
    b = _find_(b);
    if (_rank_[a] < _rank_[b])
        _parent_[a] = b;
    else if (_rank_[b] < _rank_[a])
        _parent_[b] = a;
    else
    {
        _parent_[b] = a;
        _rank_[a]++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0;i < maxN;i++)
        _parent_[i] = i;
    int n, m;
    cin >> n >> m;
    for (int i = 1;i <= m;i++)
    {
        string query;
        cin >> query;
        int u, v;
        cin >> u >> v;
        if (query == "union")
            _union_(u, v);
        else
        {
            if (_find_(u) == _find_(v))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    return 0;
}
