#include <bits/stdc++.h>
using namespace std;
 main()
{
    int t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        long long l=1,r=n,mid1,mid2;
        auto check=[&](long long x){
            long long sum1=(k+k+x-1)*x/2;
            long long sum2=(k+x+k+n-1)*(n-x)/2;
            return abs(sum1-sum2);
        };
        while(r-l>2){
            mid1=l+(r-l)/3;
            mid2=r-(r-l)/3;
            if(check(mid1)<check(mid2)){
                r=mid2-1;
            }else{
                l=mid1+1;
            }
        }
        long long ans=check(l);
        for(long long i=l;i<=r;i++){
            ans=min(ans,check(i));
        }
        cout<<ans<<endl;
    }

    return 0;
}