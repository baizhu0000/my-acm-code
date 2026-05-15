#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> q;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x;
            cin >> x;
            q.push(x);
        }
        else if (op == 2)
        {
            cout << q.top() << "\n";
            q.pop();
        }
    }
    return 0;
}