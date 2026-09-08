#include <bits/stdc++.h>
using namespace std;
int n,k;
int ans=0;
void dfs(int pos,int val,int sum){
    if(pos==k){
        int last=n-sum;
        if(last>=val){
            ans++;
        }
        return ;
    }
    for(int i=val;i<=(n-sum)/(k-pos+1);i++){
        dfs(pos+1,i,sum+i);
    }
}
int main()
{
    cin>>n>>k;
    dfs(1,1,0);
    cout<<ans<<endl;
    return 0;
}