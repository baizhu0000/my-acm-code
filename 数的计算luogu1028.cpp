#include <iostream>
#define maxn 10005
using namespace std;
int a[10005]={0};
int n;
int solve(int x){
    int ans=1;
    if(a[x]!=0){;
        return a[x];
    }
    for(int i=1;i<=x/2;i++){
        ans+=solve(i);
    }
    return a[x]=ans;
}
int main()
{
    cin>>n;
    a[1]=1;
    cout<<solve(n);   
    return 0;
}