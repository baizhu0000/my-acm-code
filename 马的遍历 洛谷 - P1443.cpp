#include <bits/stdc++.h>
using namespace std;
struct pos
{
    int x,y;
};
const int maxn=401;
queue<pos>q;
int ans[maxn][maxn];
int walk[8][2]={{2,1},{2,-1},{-1,2},{1,2},{-2,1},{-2,-1},{1,-2},{-1,-2}};
int main()
{
    int n,m,sx,sy;
    memset(ans,-1,sizeof(ans));
    cin>>n>>m>>sx>>sy;
    pos tmp;
    tmp.x=sx;
    tmp.y=sy;
    q.push(tmp);
    ans[sx][sy]=0;
    while(!q.empty()){
        pos u=q.front();
        int ux=u.x,uy=u.y;
        q.pop();
        for(int i=0;i<8;i++){
            int x=ux+walk[i][0],y=uy+walk[i][1];
            int d=ans[ux][uy];
            if(x<1||x>n||y<1||y>m||ans[x][y]!=-1){
                continue;
            }
            ans[x][y]=d+1;
            pos temp;
            temp.x=x;
            temp.y=y;
            q.push(temp);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}