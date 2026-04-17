#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n;
struct aa
{
    int cnt,g;
    bool operator<(const aa&a)const{
        return g<a.g;
    }
}a[N];
bool check(int x){
    for(int i=0;i<n;i++){
        if(x<a[i].g){
            return false;
        }
        x+=a[i].cnt;
    }
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].cnt;
            a[i].g=0;
            for(int j=0;j<a[i].cnt;j++){
                int x;
                cin>>x;
                a[i].g=max(a[i].g,x-j+1);
            }
        }
        sort(a,a+n);
        int l=0,r=1e9+1;
        while(l<r){
            int mid=l+(r-l)/2;
            if(check(mid)){
                r=mid;
            }else{
                l=mid+1;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}