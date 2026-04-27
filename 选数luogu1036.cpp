#include <iostream>
#include <cstdio>
using namespace std;
int a[30];
bool pd(int x){
    if(x<2){
        return false;
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return false;
        }
    }
    return true;
}
int main()
{
    int n,k,cnt=0;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int u=1<<n;
    for(int s=0;s<u;s++){
        if(__builtin_popcount(s)==k){
            int sum=0;
            for(int i=0;i<n;i++){
                if(s&(1<<i)){
                    sum+=a[i];
                }
            }
            if(pd(sum)){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}