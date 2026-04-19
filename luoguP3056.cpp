#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int pd = 0, ans = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            pd++;
        }
        else if (s[i] == ')')
        {
            pd--;
        }
        if (pd < 0)
        {
            ans++;
            pd += 2;
        }
    }
    if (pd != 0)
    {
        ans += pd / 2;
    }
    cout << ans << endl;
    return 0;
}