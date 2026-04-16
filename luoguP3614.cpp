#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        stack<int> st;
        int n;
        cin >> n;
        while (n--)
        {
            string s;
            cin >> s;
            if (s == "push")
            {
                int x;
                cin >> x;
                st.push(x);
            }
            else if (s == "pop")
            {
                if (st.empty())
                {
                    cout << "Empty" << "\n";
                }
                else
                {
                    st.pop();
                }
            }
            else if (s == "query")
            {
                if (st.empty())
                {
                    cout << "Anguei!" << "\n";
                }
                else
                {
                    cout << st.top() << "\n";
                }
            }
            else if (s == "size")
            {
                cout << st.size() << "\n";
            }
        }
    }

    return 0;
}