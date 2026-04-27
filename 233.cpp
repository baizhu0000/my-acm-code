#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>a(n);
        for(long long i=0;i<n;i++){
            cin>>a[i];
        }
        long long ans=0;
        long long temp=0,sum=0;
        for(long long i=0;i<n;i++){
            temp+=a[i];
            if(temp>sum){
                ans++;
                sum=temp;
                temp=0;
            }   
        }
        cout<<ans<<endl;
    }

    return 0;
}