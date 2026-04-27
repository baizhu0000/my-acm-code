#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int d[N],a[N]; 
int ans[2];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int s=1e6+5,e=0;
    for(int i=0;i<n;i++){
        int l,r;
        cin>>l>>r;
        s=min(s,l);
        e=max(e,r);
        d[l]++;
        d[r]--;
    }
    for(int i=s;i<=e;i++){
        a[i]=a[i-1]+d[i];
    }
    int p=0;
    int cnt=0;
    for(int i=s;i<=e;i++){
        bool cur=a[i];
        if(p!=cur){
            ans[p]=max(ans[p],cnt);
            cnt=1;
            p=cur;
        }else{
            cnt++;
        }
    }
    cout<<ans[1]<<" "<<ans[0]<<endl;

    return 0;
}