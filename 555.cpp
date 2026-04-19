#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>ans(n+1,0);
        if(n==1){
            ans[1]=m;
        }else{
            int b=(n-1)/2;
            ans[1]=m-b;
            int idx=3;
            for(int i=0;i<b;i++){
                if(idx<=n){
                    ans[idx]=1;
                    idx+=2;
                }
            }
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }

    return 0;
}