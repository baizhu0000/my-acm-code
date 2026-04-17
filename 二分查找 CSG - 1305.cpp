#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        a[i]=(int)(100 * sin(n + i)) % 3;
    }
    vector<long long>b(n);
    b[0]=a[0];
    for(int i=1;i<n;i++){
        b[i]=b[i-1]+a[i];
    }
    while(m--){
        long long x;
        cin>>x;
        auto l=lower_bound(b.begin(),b.end(),x);
        auto u=upper_bound(b.begin(),b.end(),x);
        int lidx,uidx;
        if(l!=b.end()){
            lidx=l-b.begin();
        }else{
            lidx=-1;
        }
        if(u!=b.end()){
            uidx=u-b.begin();
        }else{
            uidx=-1;
        }
        cout<<lidx<<" "<<uidx<<endl;
    }

    return 0;
}