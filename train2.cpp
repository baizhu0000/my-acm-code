#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int cnt = 0;
    for (int q = 1; q <= n; q++)
    {
        for (int w = q + 1; w <= n; w++)
        {
            for (int e = w + 1; e <= n; e++)
            {
                for (int r = e + 1; r <= n; r++)
                {
                    if (a[q] < a[w] && a[w] == a[e] && a[e] > a[r])
                    {
                        cnt = (cnt + 1) % 10007;
                    }
                }
            }
        }
    }
    cout << cnt;
    return 0;
}