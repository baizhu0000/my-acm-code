#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n;
int dist[maxn][maxn];
bool vis[maxn][maxn];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool pd(int x,int y){
    return x>=1&&x<=n&&y>=1&&y<=n;
}
bool bfs(){
    memset(vis,0,sizeof(vis));
    queue<int>qx,qy,qt;
    qx.push(1);
    qy.push(1);
    qt.push(0);
    vis[1][1]=true;
    while(!qx.empty()){
        int x=qx.front();
        qx.pop();
        int y=qy.front();
        qy.pop();
        int t=qt.front();
        qt.pop();
        if(x==n&&y==n){
            return true;
        }
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nt=t+1;
            if(!pd(nx,ny)){
                continue;
            }
            if(vis[nx][ny]){
                continue;
            }
            if(dist[nx][ny]!=-1&&nt>dist[nx][ny]){
                continue;
            }
            vis[nx][ny]=true;
            qx.push(nx);
            qy.push(ny);
            qt.push(nt);
        }
    }
    return false;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        memset(dist,-1,sizeof(dist));
        for(int i=0;i<2*n-2;i++){
            int x,y;
            cin>>x>>y;
            dist[x][y]=i+1;
        }
        if(bfs()){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}