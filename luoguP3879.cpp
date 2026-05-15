#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<string, set<int>> ma;
    for (int i = 1; i <= n; i++)
    {
        int l;
        cin >> l;
        while (l--)
        {
            string s;
            cin >> s;
            ma[s].insert(i);
        }
    }
    int m;
    cin >> m;
    while (m--)
    {
        string pd;
        cin >> pd;
        if (ma.find(pd) != ma.end())
        {
            for (int i : ma[pd])
            {
                cout << i << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
// 3
// 9 you are a good boy ha ha o yeah
// 13 o my god you like bleach naruto one piece and so do i
// 11 but i do not think you will get all the points
// 5
// you
// i
// o
// all
// naruto

// 1 2 3
// 2 3
// 1 2
// 3
// 2
