#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int nex[maxn];
int main()
{
    nex[1]=0;
    int q;
    cin>>q;
    while(q--){
        int num,x,y;
        cin>>num>>x;
        if(num==1){
            cin>>y;
            int temp=nex[x];
            nex[x]=y;
            nex[y]=temp;
        }else if(num==2){
            cout<<nex[x]<<endl;
        }else if(num==3){
            int temp=nex[x];
            nex[x]=nex[temp];
        }
    }
    return 0;
}