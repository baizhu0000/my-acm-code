#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int>t(n);
    for(int i=0;i<n;i++){
        cin>>t[i];
    }
    vector<int>you(n,1);
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(t[j]<t[i]){
                you[i]=max(you[i],you[j]+1);
            }
        }
    }
    vector<int>zuo(n,1);
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(t[j]<t[i]){
                zuo[i]=max(zuo[i],zuo[j]+1);
            }
        }
    }
    int len=0;
    for(int i=0;i<n;i++){
        len=max(len,zuo[i]+you[i]-1);
    }
    cout<<n-len;
    return 0;
}