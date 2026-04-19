#include <bits/stdc++.h>
using namespace std;
int num[20005];
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        num[x]++;
        if(num[x]==1){
            cout<<x<<" ";
        }
    }

    return 0;
}