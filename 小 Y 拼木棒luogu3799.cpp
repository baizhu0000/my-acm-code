#include <iostream>
using namespace std;
const int x=1e9+7;
int main()
{
    int n;
    cin>>n;
    int a[n];
    long long ans=0;
    int cnt[5001]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=2;i<5001;i++){
        if(cnt[i]<2){
            continue;
        }
        long long plan=(long long)cnt[i]*(cnt[i]-1)/2%x;
        for(int a=1;a<=i-a;a++){
            int b=i-a;
            if(a>5000||b>5000){
                continue;
            }
            if(a==b){
                if(cnt[a]>=2){
                    long long plan2=(long long)cnt[a]*(cnt[a]-1)/2%x;
                    ans=(ans+plan*plan2)%x;
                }
            }else{
                if(cnt[a]>0&&cnt[b]>0){
                    long long plan3=(long long)cnt[a]*cnt[b]%x;
                    ans=(ans+plan*plan3)%x;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}