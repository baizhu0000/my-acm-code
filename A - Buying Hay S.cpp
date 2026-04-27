#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main()
{
    int n,h;
    cin>>n>>h;
    vector<int>p(n);
    vector<int>c(n);
    for(int i=0;i<n;i++){
        cin>>p[i]>>c[i];
    }
    vector<int>dp(h+1,inf);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<=h;j++){
            if(dp[j]<inf){
                int temp=min(j+p[i],h);
                dp[temp]=min(dp[temp],dp[j]+c[i]);
            }
        }
    }
    cout<<dp[h];
    return 0;
}