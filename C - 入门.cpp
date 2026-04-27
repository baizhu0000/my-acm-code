#include <bits/stdc++.h>
using namespace std;
int w,h;
vector<string>a;
vector<vector<bool>>pd;
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
int dfs(int x,int y){
    pd[x][y]=true;
    int cnt=1;
    for(int i=0;i<4;i++){
        int nx=dx[i]+x;
        int ny=dy[i]+y;
        if(nx>=0&&nx<h&&ny>=0&&ny<w&&!pd[nx][ny]&&(a[nx][ny]=='.'||a[nx][ny]=='@')){
            cnt+=dfs(nx,ny);
        }
    }
    return cnt;
}

int main()
{
    cin>>w>>h;
    a.resize(h);
    pd.resize(h,vector<bool>(w,false));
    for(int i=0;i<h;i++){
        cin>>a[i];
    }
    int sx=-1,sy=-1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]=='@'){
                sx=i;
                sy=j;
                break;
            }
        }
        if(sx!=-1){
            break;
        }
    }
    int ans=dfs(sx,sy);
    cout<<ans<<endl;
    return 0;
}