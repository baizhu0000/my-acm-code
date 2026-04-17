#include <bits/stdc++.h>
using namespace std;
struct cho{
    long long a,b,c;
    bool operator<(const cho& x)const{
        return b>x.b;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,n;
    cin>>x>>n;
    vector<cho>cnt(n);  
    for(int i=0;i<n;i++){
        cin>>cnt[i].a>>cnt[i].b>>cnt[i].c;
    }
    sort(cnt.begin(),cnt.end());
    vector<pair<long long,long long>>use;
    long long ans=0;
    int idx=0;
    for(int d=x;d>=1;d--){
        while(idx<n&&cnt[idx].b>=d){
            use.push_back({cnt[idx].a,cnt[idx].c});
            idx++;
        }
        if(use.empty()){
            cout<<-1<<endl;
            return 0;
        }
        int mi=0;
        for(int j=1;j<use.size();j++){
            if(use[j].first<use[mi].first){
                mi=j;
            }
        }
        ans+=use[mi].first;
        use[mi].second--;
        if(use[mi].second==0){
            use[mi]=use.back();
            use.pop_back();
        }
    }
    cout<<ans<<endl;
    return 0;
}