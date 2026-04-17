#include <bits/stdc++.h>
using namespace std;
int main(){
    int H,T;
    cin>>H>>T;
    int n;
    cin>>n;
    vector<int>h(n),t(n),k(n);
    for(int i=0;i<n;i++){
        cin>>h[i]>>t[i]>>k[i];
    }
    vector<vector<int>>dp(H+1,vector<int>(T+1,0));
    for(int idx=0;idx<n;idx++){
        for(int i=H;i>=h[idx];i--){
            for(int j=T;j>=t[idx];j--){
                dp[i][j] = max(dp[i][j], dp[i - h[idx]][j - t[idx]] + k[idx]);
            }
        }
    }
    cout<<dp[H][T];
    return 0;
}