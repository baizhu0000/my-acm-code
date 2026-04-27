#include <bits/stdc++.h>
using namespace std;
int nex[100005],pre[100005];
int main()
{
    int n;
    cin>>n;
    nex[1]=0;
    pre[1]=0;
    bool remove[100005];
    memset(remove, false, sizeof(remove));
    for(int i=2;i<=n;i++){
        int k,p;
        cin>>k>>p;
        if(p==0){
            int temp=pre[k];
            nex[i]=k;
            pre[i]=temp;
            if(temp!=0){
                nex[temp]=i;
            }
            pre[k]=i;
        }else if(p==1){
            int temp=nex[k];
            pre[i]=k;
            nex[i]=temp;
            if(temp!=0){
                pre[temp]=i;
            }
            nex[k]=i;
        }
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        if(remove[x]){
            continue;
        }
        remove[x]=true;
        int tz=pre[x];
        int ty=nex[x];
        if(tz!=0){
            nex[tz]=ty;
        }
        if(ty!=0){
            pre[ty]=tz;
        }
        pre[x]=nex[x]=0;
    }
    int s=1;
    while(s<=n&&(pre[s]!=0||remove[s])){
        s++;
    }
    bool first=true;
    while(s!=0&&!remove[s]){
        if(!first){
            cout<<" ";
        }
        cout<<s;
        first=false;
        s=nex[s];
    }
    return 0;
}