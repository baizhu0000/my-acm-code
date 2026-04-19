#include <bits/stdc++.h>
using namespace std;
long long n;
bool check(long long mid){
    long long sum=(mid+1)*(mid+1);
    return sum>=n;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        long long l=0,r=1e9;
        while(l<r){
            long long mid=l+(r-l)/2;
            if(check(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<l<<endl;
    }   

    return 0;
}