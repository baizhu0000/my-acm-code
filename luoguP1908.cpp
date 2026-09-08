#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n;
vector<int>a(maxn),b(maxn);
int tree[maxn];
long long ans=0;
int lowbit(int x){
    return x&-x;
}
void add(int pos,int val){
    while(pos<=n){
        tree[pos]+=val;
        pos+=lowbit(pos);
    }
}
int query(int pos){
    int sum=0;
    while(pos>0){
        sum+=tree[pos];
        pos-=lowbit(pos);
    }
    return sum;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin()+1,b.end());
    b.erase(unique(b.begin()+1,b.end()),b.end());
    for(int i=1;i<=n;i++){
        int pos=lower_bound(b.begin()+1,b.end(),a[i])-b.begin();
        ans+=(i-1)-query(pos);
        add(pos,1);
    }
    cout<<ans<<endl;
    return 0;
}