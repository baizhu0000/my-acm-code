#include <bits/stdc++.h>
using namespace std;
int cnt[200005];
int main()
{
    int n;
    cin >> n;
    string s;
    int w;
    while (cin >> s)
    {
        if (s == "add")
        {
            cin >> w;
            cnt[0]++;
        }
        else if (s == "sync")
        {
            cin >> w;
            cnt[w]++;
        }
        else if (s == "query")
        {
            int ans = 1000005;
            for (int i = 0; i < n; i++)
            {
                ans = min(ans, cnt[i]);
            }
            cout << ans << "\n";
        }
    }
    return 0;
}