#include <bits/stdc++.h>
using namespace std;
long long n, m, op;
long long k, a[300005], x, w = 0;
signed main()
{
    cin >> n >> m >> k;
    long long l = 1, r = n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> op;
        if (op == 3)
        {
            cout << r - l + 1 << endl;
            continue;
        }
        cin >> x;
        if (op == 1)
        {
            w = w + x;
            while (a[r] + w > k && l <= r)
            {
                r--;
            }
        }
        else if (op == 2)
        {
            w = w - x;
            while (a[l] + w < -k && l <= r)
            {
                l++;
            }
        }
    }
    return 0;
}
