#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
int main()
{
    int K, D, M, F;
    cin >> K >> D >> M >> F;
    int x;
    priority_queue<int> k;
    priority_queue<int> d;
    priority_queue<int> m;
    priority_queue<int> f;
    for (int i = 0; i < K; i++)
    {
        cin >> x;
        k.push(x);
    }
    for (int i = 0; i < D; i++)
    {
        cin >> x;
        d.push(x);
    }
    for (int i = 0; i < M; i++)
    {
        cin >> x;
        m.push(x);
    }
    for (int i = 0; i < F; i++)
    {
        cin >> x;
        f.push(x);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        double sum = 0;
        sum += k.top();
        k.pop();
        while (a--)
        {
            sum += d.top();
            d.pop();
        }
        while (b--)
        {
            sum += m.top();
            m.pop();
        }
        while (c--)
        {
            sum += f.top();
            f.pop();
        }
        double ans = sum / 11;
        cout << fixed << setprecision(2) << ans << "\n";
    }
    return 0;
}