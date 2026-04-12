#include<iostream>
#define maxn 2000
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[10]={6,2,5,5,4,5,6,3,7,6};
    int cnt=0;
    if(n<4+3*2){
        cout<<0;
        return 0;
    }
    int num[maxn+1];
    for(int i=0;i<=maxn;i++){
        if(i==0){
            num[i]=6;
        }else{
            int x=i,sum=0;
            while(x>0){
                sum+=a[x%10];
                x/=10;
            }
            num[i]=sum;
        }
    }
    int use=n-4;
    for(int i=0;i<=maxn;i++){
        for(int j=0;j<=maxn;j++){
            int c=i+j;
            if(c>maxn){
                continue;
            }
            if(num[i]+num[j]+num[c]==use){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}