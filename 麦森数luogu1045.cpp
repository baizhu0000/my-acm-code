#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int maxn=500;

long long ans[maxn]={1};

void chen(long long ans[maxn],int x){
    long long c=0;
    for(int i=0;i<maxn;i++){
        long long p=ans[i]*x+c;
        ans[i]=p%10;
        c=p/10;
    }
}
void jian(long long ans[maxn]){
    int i=0;
    while(i<maxn&&ans[i]==0){
        ans[i]=9;
        i++;
    }
    if(i<maxn){
        ans[i]--;
    }
}
int main()
{
    int p;
    cin>>p;
    int q;
    q=ceil(p*(log(2)/log(10)));
    cout<<q<<endl;
    int n=p/30,t=p%30;
    int x=1;
    for(int i=0;i<30;i++){
        x*=2;
    }
    for(int i=0;i<n;i++){
        chen(ans,x);
    }
    for(int i=0;i<t;i++){
        chen(ans,2);
    }
    jian(ans);
    int cnt=0;
    for(int i=maxn-1;i>=0;i--){
        cout<<ans[i];
        cnt++;
        if(cnt==50){
            cout<<endl;
            cnt=0;
        }
    }

    return 0;
}