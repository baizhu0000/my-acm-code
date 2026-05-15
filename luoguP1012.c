#include <bits/stdc++.h>
using namespace std;
bool pd(string a, string b)
{
    if (a + b > b + a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> a;
    while (n--)
    {
        string x;
        cin >> x;
        a.push_back(x);
    }
    sort(a.begin(), a.end(), pd);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }

    return 0;
}