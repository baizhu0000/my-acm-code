#include <bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    int l=1,r=0,sum=0;
    while(l<=m/2){
        if(sum==m){
            cout<<l<<" "<<r<<endl;
            sum-=l;;
            l++;
        }else if(sum<m){
            r++;
            sum+=r;
        }else{
            sum-=l;
            l++;
        }
    }
    return 0;
}