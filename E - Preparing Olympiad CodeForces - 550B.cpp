#include <bits/stdc++.h>
using namespace std;
int n,l,r,x,ans=0;
int c[16];
void dfs(int d,int sum,int mi,int ma){
    if(sum>r){
        return;
    }
    if(d==n){
        if(sum>=l&&ma-mi>=x){
            ans++;
        }
        return ;
    }
    dfs(d+1,sum,mi,ma);
    dfs(d+1,sum+c[d+1],min(mi,c[d+1]),max(ma,c[d+1]));
}

int main()
{
    cin>>n>>l>>r>>x;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    dfs(0,0,1e9+10,0);
    cout<<ans;
    return 0;
}