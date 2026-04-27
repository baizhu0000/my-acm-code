#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int mi=1,sum=0;
    for(int i=1;i<=k;i++){
        sum+=a[i];
    }
    for(int i=2;i<=n-k+1;i++){
        int temp=sum-a[i-1]+a[i+k-1];
        sum=temp;
        if(temp<sum){
            mi=i;
        }
    }
    cout<<mi;
    return 0;
}