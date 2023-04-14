// Problem Link - https://codeforces.com/edu/course/2/lesson/7/1/practice/contest/289390/problem/D
/**
* author: mj_riffu
* created: 2023-04-12 22:50:11
**/
#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e5 + 10;
int _parent_[maxN], _rank_[maxN];
int _find_(int node)
{
    if (node == _parent_[node])
        return node;
    return _parent_[node] = _find_(_parent_[node]);
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 0;i < maxN;i++)
        _parent_[i] = i;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1;i <= m;i++)
    {
        int u, v;
        cin >> u >> v;
    }
    map<int, tuple<string, int, int>, greater<int>> mp;
    for (int i = 1;i <= k;i++)
    {
        string a;
        cin >> a;
        int u, v;
        cin >> u >> v;
        mp[i] = make_tuple(a, u, v);
    }
    vector<string> ans;
    for (auto val : mp)
    {
        tuple<string, int, int> t = val.second;
        string query;
        int u, v;
        query = get<0>(t);
        u = get<1>(t);
        v = get<2>(t);
        if (query == "ask")
        {
            if (_find_(u) == _find_(v))
                ans.push_back("YES");
            else
                ans.push_back("NO");
        }
        else
            _union_(u, v);
    }
    reverse(ans.begin(), ans.end());
    for (auto val : ans)
        cout << val << '\n';
    cout << '\n';
    return 0;
}