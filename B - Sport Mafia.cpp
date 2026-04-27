#include <bits/stdc++.h>
using namespace std;
long long l,r,n,k;
bool check(long long mid){
    long long m=n-mid;
    long long sum;
    if(m%2==0){
        sum=(m/2)*(m+1);
    }else{
        sum=m*((m+1)/2);
    }
    sum-=mid;
    return sum>=k;
}
int main()
{
    cin>>n>>k;
    l=0;
    r=n-1;
    long long ans=0;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<r<<endl;

    return 0;
}