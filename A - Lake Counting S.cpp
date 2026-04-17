#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<string>a;
vector<vector<bool>>pd;
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={1,0,-1,-1,1,-1,0,1};
void dfs(int x,int y){
    pd[x][y]=true;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&ny>=0&&nx<n&&ny<m&&!pd[nx][ny]&&a[nx][ny]=='W'){
            dfs(nx,ny);
        }
    }
}
int main()
{
    cin>>n>>m;
    a.resize(n);
    pd.resize(n,vector<bool>(m,false));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'&&!pd[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}