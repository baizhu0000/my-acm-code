#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int n;
int l[maxn],r[maxn];
int ans=0;
void dfs(int u,int d){
    if(u==0){
        return ;
    }
    ans=max(ans,d);
    dfs(l[u],d+1);
    dfs(r[u],d+1);

}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i]>>r[i];
    }
    dfs(1,1);
    cout<<ans<<endl;

    return 0;
}