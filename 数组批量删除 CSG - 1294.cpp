#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        a[i] = (int)(sin(n + i) * 1000000);
    }
    while (m--)
    {
        int s, e, l, r;
        cin >> s >> e >> l >> r;
        if (e >= a.size())
        {
            e = a.size();
        }
        if (s != e && s < a.size())
        {
            a.erase(a.begin() + s, a.begin() + e);
        }

        bool pd = false;
        if (l == r)
        {
            cout << "null" << endl;
            continue;
        }
        if (r >= a.size())
        {
            r = a.size();
        }
        for (int i = l; i < r; i++)
        {
            cout << a[i] << " ";
            pd = true;
        }
        if (pd)
        {
            cout << endl;
        }
        else
        {
            cout << "null" << endl;
        }
    }
    return 0;
}