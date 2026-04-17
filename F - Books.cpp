#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,t;
    cin>>n>>t;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0,ans=0;
    int l=0,r=0;
    while(r<n){
        sum+=a[r];
        r++;
        while(sum>t&&l<r){
            sum-=a[l];
            l++;
        }
        ans=max(ans,r-l);
    }
    cout<<ans;
    return 0;
}