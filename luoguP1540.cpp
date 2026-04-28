#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;

    queue<int> q;
    bool pd[1005] = {false};
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (!pd[x])
        {
            pd[x] = true;
            ans++;
            q.push(x);
            if (q.size() > m)
            {
                pd[q.front()] = false;
                q.pop();
            }
        }
    }

    cout << ans << endl;
    return 0;
}