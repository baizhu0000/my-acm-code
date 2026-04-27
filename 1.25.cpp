#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,q;
        cin>>n>>q;
        int a[n];
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        for(int j=0;j<n;j++){
            int b;
            cin>>b;
            if(b>a[j]){
                a[j]=b;
            }
        }
        for(int j=n-2;j>=0;j--){
            if(a[j+1]>a[j]){
                a[j]=a[j+1];
            }
        }
        for(int j=0;j<q;j++){
            int l,r;
            cin>>l>>r;
            int sum=0;
            for(int k=l-1;k<r;k++){
                sum+=a[k];
            }
            cout<<sum<<" ";
        }
        cout<<endl;
    }

    return 0;
}