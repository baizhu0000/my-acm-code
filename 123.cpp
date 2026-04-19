#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n+1);
    int ans=1e9;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int>d(n+1,-1);
    queue<int>q;
    for(int i=1;i<=m;i++){
        if(d[i]==-1){
            d[i]=1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int k=q.front();
        q.pop();
        if(k==n){
            cout<<d[k]<<endl;
            return 0;
        }
        int temp=k+a[k];
        if(temp>0&&temp<=n&&d[temp]==-1){
            d[temp]=d[k]+1;
            q.push(temp);
        }
    }
    cout<<-1<<endl;
    return 0;
}