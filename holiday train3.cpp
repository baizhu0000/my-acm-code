#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n;
        long long he[n+1]={0};
        cin>>s;
        map<long long,long long>mp;
        mp[0]=1;
        for(int i=1;i<=n;i++){
            he[i]=he[i-1]+(int)(s[i-1]-'0');
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            long long x=he[i]-i;
            ans+=mp[x];
            mp[x]++;
        }
        cout<<ans<<endl;
    }
    return 0;
}