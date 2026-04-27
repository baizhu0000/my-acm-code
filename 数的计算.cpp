#include <iostream>
using namespace std;
int a[1010]={0};
int solve(int x){
    if(a[x]!=0){
        return a[x];
    }
    int ans=1;
    for(int i=1;i<=x/2;i++){
        ans+=solve(i);
    }
    return a[x]=ans;
}
int main()
{
    int n;
    cin>>n;
    a[1]=1;
    cout<<solve(n);

    return 0;
}