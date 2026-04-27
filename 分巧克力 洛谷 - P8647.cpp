#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int n,k;
int h[maxn],w[maxn];
bool check(int x){
    if(x==0){
        return false;
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(long long)(h[i]/x)*(w[i]/x);
        if(cnt>=k){
            return true;
        }
    }
    return cnt>=k;
}
int main()
{
    cin>>n>>k;
    int size=0;
    for(int i=1;i<=n;i++){
        cin>>h[i]>>w[i];
        size=max(size,min(h[i],w[i]));
    }
    int l=1,r=size;
    int ans=1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(check(mid)){
            l=mid+1;
            ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}