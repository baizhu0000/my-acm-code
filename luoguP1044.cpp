#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<long long>> dp(n + 2, vector<long long>(n + 2, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                continue;
            }
            if (i > 0)
            {
                dp[i][j] += dp[i - 1][j + 1];
            }
            if (j > 0)
            {
                dp[i][j] += dp[i][j - 1];
            }
        }
    }
    cout << dp[n][0] << endl;
    return 0;
}