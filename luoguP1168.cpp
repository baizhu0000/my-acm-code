#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (l.empty() || x <= l.top())
        {
            l.push(x);
        }
        else
        {
            r.push(x);
        }
        if (l.size() > r.size() + 1)
        {
            r.push(l.top());
            l.pop();
        }
        if (r.size() > l.size())
        {
            l.push(r.top());
            r.pop();
        }
        if (i % 2 == 1)
        {
            cout << l.top() << endl;
        }
    }
    return 0;
}