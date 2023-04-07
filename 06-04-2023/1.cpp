/**
* author: mj_riffu
* created: 2023-04-06 22:07:52
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0;i < n;i++)
        cin >> v[i];
    int l = 0, r = 0, sum = 0, ans = -1;

    while (r < n)
    {
        sum += v[r];
        if (r - l + 1 < k)
            r++;
        else if (r - l + 1 == k)
        {
            ans = max(ans, sum);
            sum -= v[l];
            l++;
            r++;
        }
    }
    cout << ans << '\n';
    return 0;
}