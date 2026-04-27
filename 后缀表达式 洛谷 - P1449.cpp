#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int idx = 0;
    int n = 0;
    char c;
    vector<int> num;
    while (s[idx] != '@')
    {
        if (s[idx] == '.')
        {
            num.push_back(n);
            n = 0;
        }
        else if (s[idx] <= '9' && s[idx] >= '0')
        {
            int x = s[idx] - '0';
            n = n * 10 + x;
        }
        else
        {
            int b = num.back();
            num.pop_back();
            int a = num.back();
            num.pop_back();
            char c = s[idx];
            int res;
            if (c == '+')
            {
                res = a + b;
            }
            else if (c == '-')
            {
                res = a - b;
            }
            else if (c == '*')
            {
                res = a * b;
            }
            else
            {
                res = a / b;
            }
            num.push_back(res);
        }
        idx++;
    }
    cout << num.back() << endl;
    return 0;
}