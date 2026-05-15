#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    map<long long, int> cnta, cntb;
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        cnta[a * i]++;
    }
    for (int i = 1; i <= m; i++)
    {
        long long b;
        cin >> b;
        cntb[b * i]++;
    }
    long long ans = 0;
    for (auto &p : cnta)
    {
        long long x = p.first;
        if (cntb.find(x) != cntb.end())
        {
            ans += (long long)p.second * cntb[x];
        }
    }
    cout << ans << endl;
    return 0;
}