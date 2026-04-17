#include <bits/stdc++.h>
using namespace std;
const int mod=1e6+7;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=min(a[i],j);k++){
                dp[i][j]=(dp[i][j]+dp[i-1][j-k])%mod;
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}