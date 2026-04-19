#include <bits/stdc++.h>
using namespace std;
struct rule
{
    int u,v;
    double p;
};

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,a;
        cin>>n>>m>>a;
        vector<rule> r(m);
        for(int i=0;i<m;i++){
            int x,u,y,v;
            cin>>x>>u>>y>>v;
            r[i]={u,v,(double)y/x};
        }
        vector<double>d(n+1,-1e18);
        d[a]=0.0;
        bool pd=false;
        for(int i=1;i<=n;i++){
            bool change=false;
            for(int j=0;j<m;j++){
                int u=r[j].u;
                int v=r[j].v;
                double p=r[j].p;
                if(d[u]>-1e17){
                    double nd=d[u]+log(p);
                    if(nd>d[v]+1e-12){
                        d[v]=nd;
                        change=true;
                    }
                } 
            }
            if(i==n&&change){
                pd=true;
            }
        }
        if(pd){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }

    }

    return 0;
}