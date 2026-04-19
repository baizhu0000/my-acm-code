#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0,r=0,ansl=0,ansr=0;
    long long sum=0;
    long long maxsum=0;
    while(r<n){
        while(r<n&&sum+a[r]<=m){
            sum+=a[r];
            r++;
        }
        if(sum<=m&&sum>maxsum){
            maxsum=sum;
            ansl=l;
            ansr=r-1;
        }
        if(l<r){
            sum-=a[l];
            l++;
        }else{
            l++;
            r++;
        }
    }
    cout<<ansl+1<<" "<<ansr+1<<" "<<maxsum;
    return 0;
}