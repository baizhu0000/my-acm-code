#include <bits/stdc++.h>
using namespace std;

struct motion
{
    int flag, x, y;
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 5), b(n + 5);
    for (int i = 1; i <= n; i++)
    {
        a[i] = (int)(10000 * sin(n + i));
        b[i] = (int)(10000 * cos(n + i));
    }

    vector<motion> ops(m);
    for (int i = 0; i < m; i++)
    {
        cin >> ops[i].flag >> ops[i].x >> ops[i].y;
    }

    int s, e;
    cin >> s >> e;

    for (int pos = s; pos < e; pos++)
    {
        int cur = pos;
        int group = 0;

        for (int i = m - 1; i >= 0; i--)
        {
            int flag = ops[i].flag;
            int x = ops[i].x;
            int y = ops[i].y;

            if (flag == 0)
            {
                if (group == 0)
                {
                    if (cur < x)
                    {
                    }
                    else if (cur == x)
                    {
                        group = 1;
                        cur = y;
                    }
                    else
                    {
                        cur++;
                    }
                }
                else
                {
                    if (cur > y)
                    {
                        cur--;
                    }
                    else if (cur == y)
                    {
                        group = 0;
                        cur = x;
                    }
                }
            }
            else
            {
                if (group == 1)
                {
                    if (cur < x)
                    {
                    }
                    else if (cur == x)
                    {
                        group = 0;
                        cur = y;
                    }
                    else
                    {
                        cur++;
                    }
                }
                else
                {
                    if (cur > y)
                    {
                        cur--;
                    }
                    else if (cur == y)
                    {
                        group = 1;
                        cur = x;
                    }
                }
            }
        }

        if (group == 0)
        {
            cout << a[cur] << '\n';
        }
        else
        {
            cout << b[cur] << '\n';
        }
    }

    return 0;
}