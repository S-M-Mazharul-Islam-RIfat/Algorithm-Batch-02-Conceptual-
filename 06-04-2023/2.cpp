// Problem Link - https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/A

/**
* author: mj_riffu
* created: 2023-04-06 23:11:17
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0;i < n;i++)
        cin >> v[i];

    long long int l = 0, r = 0, sum = 0, ans = 0;
    while (r < n)
    {
        sum += v[r];
        if (sum <= k)
        {
            ans = max(ans, r - l + 1);
            r++;
        }
        else if (sum > k)
        {
            while (sum > k && l <= r)
            {
                sum -= v[l];
                l++;
            }
            r++;
        }
    }
    cout << ans << '\n';
    return 0;
}