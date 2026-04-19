#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n+1]={0};
    while(m--){
        int q;
        cin>>q;
        if(q==1){
            int x,y;
            cin>>x>>y;
            for(int i=x;i<=y;i++){
                if(a[i]==0){
                    a[i]=1;
                }else{
                    a[i]=0;
                }
            }
        }else if(q==2){
            int x;
            cin>>x;
            cout<<a[x]<<endl;
        }
    }


    return 0;
}