#include <iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        int pd=1;
        for(int j=0;j<n;j++){
            if(a[n-1-j]!=b[j]){
                pd=0;
                break;
            }
        }
        if(pd==1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}