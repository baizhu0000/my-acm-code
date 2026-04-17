#include <iostream>
#include <string>
using namespace std;
void same(int *m,int &x){
    x=m[x];
}
int main()
{
    int n;
    cin>>n;
    int ans[n]={0};
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        int x=0;
        int s[t];
        string a;
        for(int j=0;j<t;j++){
            cin>>a;
            if(a[0]=='L'){
                x--;
                s[j]=-1;
            }else if(a[0]=='R'){
                x++;
                s[j]=1;
            }
        }
    }
    return 0;
}