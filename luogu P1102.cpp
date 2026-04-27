#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    cin>>n>>c;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int l=0,r=0;
    long long ans=0;
    for(int i=0;i<n;i++){
        long long tar=a[i]+c;
        while(l<n&&a[l]<tar){
            l++;
        }
        while(r<n&&a[r]<=tar){
            r++;
        }
        if(a[l]==tar){
            ans+=(r-l);
        }
    }
    cout<<ans;
    return 0;
}