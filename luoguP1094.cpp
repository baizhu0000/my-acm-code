#include <bits/stdc++.h>
using namespace std;
const int maxn=30005;
int w,n;
int a[maxn];
int main()
{
    cin>>w>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    int l=0,r=n-1;
    while(l<=r){
        if(a[l]+a[r]<=w){
            l++;
            r--;

        }else{
            r--;
        }
        ans++;
    }
    cout<<ans<<endl;

    return 0;
}