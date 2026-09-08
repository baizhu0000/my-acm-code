#include <bits/stdc++.h>
using namespace std;
const int maxn=10;
int n,m,t;
int sx,sy,fx,fy;
bool pd[maxn][maxn];
bool vis[maxn][maxn];
int ans=0;
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
void dfs(int x,int y){
    if(x==fx&&y==fy){
        ans++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&!pd[nx][ny]){
            vis[nx][ny]=true;
            dfs(nx,ny);
            vis[nx][ny]=false;
        }
    }
}
int main()
{
    cin>>n>>m>>t;
    cin>>sx>>sy>>fx>>fy;
    for(int i=0;i<t;i++){
        int x,y;
        cin>>x>>y;
        pd[x][y]=true;
    }
    vis[sx][sy]=true;
    dfs(sx,sy);
    cout<<ans<<endl;
    return 0;
}