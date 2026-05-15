#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<unsigned long long> a;
        while (n--)
        {
            string s;
            cin >> s;
            if (s == "push")
            {
                unsigned long long x;
                cin >> x;
                a.push(x);
            }
            else if (s == "pop")
            {
                if (a.empty())
                {
                    cout << "Empty" << "\n";
                }
                else
                {
                    a.pop();
                }
            }
            else if (s == "query")
            {
                if (a.empty())
                {
                    cout << "Anguei!" << "\n";
                }
                else
                {
                    cout << a.top() << "\n";
                }
            }
            else if (s == "size")
            {
                cout << a.size() << "\n";
            }
        }
    }
    return 0;
}