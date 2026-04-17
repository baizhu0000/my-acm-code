#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long n,m;
    cin>>n>>m;
    long long cntz=0,cntc=0;
    int mi=min(n,m);
    cntc=(n*(n+1)/2)*(m*(m+1)/2);
    for(int a=1;a<=mi;a++){
        cntz+=(n-a+1)*(m-a+1);
    }
    cout<<cntz<<" "<<cntc-cntz;
    return 0;
}