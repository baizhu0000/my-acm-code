#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    queue<int> a;
    for (int i = 1; i <= n; i++)
    {
        a.push(i);
    }
    while (!a.empty())
    {
        for (int i = 1; i < m; i++)
        {
            a.push(a.front());
            a.pop();
        }
        cout << a.front() << " ";
        a.pop();
    }
    return 0;
}