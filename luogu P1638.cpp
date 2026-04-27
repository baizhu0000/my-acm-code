#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> cnt(m+1,0);
    int l=1,r=1,size=0,minlen=1e9;
    int ansl,ansr;
    for(r=1;r<=n;r++){
        if(cnt[a[r]]==0){
            size++;
        }
        cnt[a[r]]++;
        while(size==m){
            if(r-l+1<minlen){
                minlen=r-l+1;
                ansl=l;
                ansr=r;
            }
            cnt[a[l]]--;
            if(cnt[a[l]]==0){
                size--;
            }
            l++;
        }
    }
    cout<<ansl<<" "<<ansr;
    return 0;
}