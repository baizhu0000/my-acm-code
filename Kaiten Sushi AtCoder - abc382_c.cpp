#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int miny=1e9;
    vector<int>a,id;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        if(x<miny){
            a.push_back(x);
            id.push_back(i);
            miny=x;
        }
    }
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        auto temp=lower_bound(a.begin(),a.end(),x,greater<int>());
        if(temp==a.end()){
            cout<<-1<<endl;
        }else{
            cout<<id[temp-a.begin()]<<endl;
        }
    }
    return 0;
}