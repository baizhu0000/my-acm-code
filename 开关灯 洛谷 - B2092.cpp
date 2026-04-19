#include <bits/stdc++.h>
using namespace std;
int lamp[5005];
int main()
{
    int n;
    cin>>n;
    int cnt=sqrt(n);
    for(int i=1;i<=cnt;i++){
        if(i>1){
            cout<<" ";
        }
        cout<<i*i;
    }

    return 0;
}