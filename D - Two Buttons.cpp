#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    queue<int>a;
    a.push(n);
    vector<int>d(1e4+10,0);
    while(a.size()){
        int u=a.front();
        a.pop();
        if(u==m){
            cout<<d[u];
            break;
        }
        if(u*2<=1e4&&!d[u*2]){
            d[u*2]=d[u]+1;
            a.push(u*2);
        }
        if(u-1>=1&&!d[u-1]){
            d[u-1]=d[u]+1;
            a.push(u-1);
        }
    }
    return 0;
}