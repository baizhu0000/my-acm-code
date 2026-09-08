#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
const int maxm = 200005;
int n,m;
int b[maxm],e[maxm],w[maxm];
int d[maxm];
int f[maxn];
int ans=0,cnt=0;
int find(int x){
    if(f[x]==x){
        return x;
    }
    return f[x]=find(f[x]);
}
void add(int x,int y){
    int fx=find(x);
    int fy=find(y);
    if(fx!=fy){
        f[fx]=fy;
    }
}
bool pd(int x,int y){
    return w[x]<w[y];
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>b[i]>>e[i]>>w[i];
        d[i]=i;
    }
    sort(d,d+m,pd);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
    for(int i=0;i<m;i++){
        int id=d[i];
        if(find(b[id])!=find(e[id])){
            add(b[id],e[id]);
            ans+=w[id];
            cnt++;
            if(cnt==n-1){
                cout<<ans<<endl;
                return 0;
            }
        }

    }
    cout<<"orz"<<endl;
    return 0;
}