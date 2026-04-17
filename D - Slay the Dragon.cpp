#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<long long>a(n);
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    sort(a.begin(),a.end());
    int m;
    cin>>m;
    while(m--){
        long long x,y;
        cin>>x>>y;
        auto i=lower_bound(a.begin(),a.end(),x)-a.begin();
        long long ans=2e18;
        if(i>0){
            ans=min(ans,(x-a[i-1])+max(0LL,y-sum+a[i-1]));
        }
        if(i<n){
            ans=min(ans,max(0LL,y-sum+a[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}