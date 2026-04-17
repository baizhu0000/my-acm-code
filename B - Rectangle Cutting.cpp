#include <bits/stdc++.h>
using namespace std;
bool pd(long long a1,long long a2,long long b1,long long b2){
    return (a1==a2&&b1==b2)||(a1==b2&&a2==b1);
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
        bool ans=false;
        if(a%2==0){
            long long na=a/2;
            long long nb=b*2;
            if(!pd(a,na,b,nb)){
                ans=true;
            }
        }
        if(b%2==0){
            long long na=2*a;
            long long nb=b/2;
            if(!pd(a,na,b,nb)){
                ans=true;
            }
        }
        if(a==1&&b==1){
            ans=false;
        }
        if(ans){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}