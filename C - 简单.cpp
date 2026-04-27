#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
const int no=1e9;
int ma[maxn][maxn];
int d[maxn][maxn];
int w,h;
int dx[4]={0,-1,0,1};
int dy[4]={-1,0,1,0};
struct point
{
    int x,y;
    point(int a,int b){
        x=a;
        y=b;
    }
};

int bfs(point s,point e,bool pass){
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            d[i][j]=no;
        }
    }
    queue<point>q;
    d[s.x][s.y]=0;
    q.push(s);
    while(!q.empty()){
        point temp=q.front();
        q.pop();
        if(temp.x==e.x&&temp.y==e.y){
            return d[temp.x][temp.y];
        }
        for(int i=0;i<4;i++){
            int tx=temp.x+dx[i];
            int ty=temp.y+dy[i];
            if(tx<0||tx>=h){
                continue;
            }
            if(ma[tx][ty]==1){
                continue;
            }
            if(pass&&ma[tx][ty]==3){
                continue;
            }
            if(d[tx][ty]==no){
                d[tx][ty]=d[temp.x][temp.y]+1;
                q.push(point(tx,ty));
            }
        }
    }
    return no;
}

int main()
{
    cin>>w>>h;
    point s(0,0);
    point k(0,0);
    vector<point>tree;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin>>ma[i][j];
            if(ma[i][j]==2){
                s=point(i,j);
            }else if(ma[i][j]==3){
                k=point(i,j);
            }else if(ma[i][j]==4){
                tree.push_back(point(i,j));
            }
        }
    }
    int ans=no;
    for(int i=0;i<tree.size();i++){
        int d1=bfs(s,tree[i],true);
        int d2=bfs(tree[i],k,false);
        if(d1<no&&d2<no){
            ans=min(ans,d1+d2);
        }
    }
    cout<<ans;
    return 0;
}