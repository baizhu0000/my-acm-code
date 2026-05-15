#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> a;
    int n;
    cin >> n;
    while (n--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int x;
            cin >> x;
            a.push(x);
        }
        else if (t == 2)
        {
            if (a.empty())
            {
                cout << "ERR_CANNOT_POP" << "\n";
            }
            else
            {
                a.pop();
            }
        }
        else if (t == 3)
        {
            if (a.empty())
            {
                cout << "ERR_CANNOT_QUERY" << "\n";
            }
            else
            {
                cout << a.front() << "\n";
            }
        }
        else if (t == 4)
        {
            cout << a.size() << "\n";
        }
    }

    return 0;
}