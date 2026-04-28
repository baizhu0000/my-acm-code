#include <bits/stdc++.h>
using namespace std;
deque<int> a[20];
int b[20], sum;
int main()
{
    char x;
    for (int i = 1; i <= 13; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cin >> x;
            if (x <= '9' && x >= '1')
            {
                a[i].push_back(x - '0');
            }
            else if (x == 'A')
            {
                a[i].push_back(1);
            }
            else if (x == '0')
            {
                a[i].push_back(10);
            }
            else if (x == 'J')
            {
                a[i].push_back(11);
            }
            else if (x == 'Q')
            {
                a[i].push_back(12);
            }
            else if (x == 'K')
            {
                a[i].push_back(13);
            }
        }
    }
    while (!a[13].empty())
    {
        int t = a[13].front();
        a[13].pop_front();
        while (t != 13)
        {
            b[t]++;
            if (b[t] >= 4)
            {
                sum++;
            }
            int p = a[t].back();
            a[t].pop_back();
            t = p;
        }
    }
    cout << sum;
    return 0;
}