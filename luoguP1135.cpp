#include <bits/stdc++.h>
using namespace std;
const int maxn=210;
int n,a,b;
int k[maxn];
int dist[maxn];
int bfs(){
    memset(dist,-1,sizeof(dist));
    queue<int >q;
    q.push(a);
    dist[a]=0;
    while(!q.empty()){
        int t=q.front();
        q.pop();
        if(t==b){
            return dist[t];
        }
        int f=k[t];
        int up=t+f;
        if(up<=n&&dist[up]==-1){
            dist[up]=dist[t]+1;
            q.push(up);
        }
        int down=t-f;
        if(down>=1&&dist[down]==-1){
            dist[down]=dist[t]+1;
            q.push(down);
        }
    }
    return -1;
    
}
int main()
{
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>k[i];
    }
    cout<<bfs()<<endl;

    return 0;
}