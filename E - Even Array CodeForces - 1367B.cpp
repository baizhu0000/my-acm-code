#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int cntj=0,cnto=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i%2==1){
                if(a[i]%2==0){
                    cnto++;
                }
            }
            if(i%2==0){
                if(a[i]%2==1){
                    cntj++;
                }
            }
        }
        if(cntj==cnto){
            cout<<cntj<<endl;
        }else{
            cout<<-1<<endl;
        }

    }

    return 0;
}