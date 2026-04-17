#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long a,b,k;
        cin>>a>>b>>k;
        long long cha=a-b,ans;
        if(k%2==0){
            long long cnt=k/2;
            ans=cnt*cha;
        }else{
            long long cnt=(k-1)/2;
            ans=cnt*cha+a;
        }
        cout<<ans<<endl;
    }

    return 0;
}