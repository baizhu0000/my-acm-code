#include <iostream>
using namespace std;
int ans(int a[],int sum,int s){
    int target=sum/2;
    bool dp[target+1]={true};
    for(int i=0;i<s;i++){
        int t=a[i];
        for(int j=target;j>=t;j--){
            if(dp[j-t]){
                dp[j]=true;
            }
        }
    }
    int x=0,y;
    for(int i=target;i>=0;i--){
        if(dp[i]){
            x=i;
            break;
        }
    }
    y=sum-x;
    if(x>y){
        return x;
    }else{
        return y;
    }
}
int main()
{
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int a[s1],b[s2],c[s3],d[s4];
    int sum1=0,sum2=0,sum3=0,sum4=0;
    for(int i=0;i<s1;i++){
        cin>>a[i];
        sum1+=a[i];
    }
    for(int i=0;i<s2;i++){
        cin>>b[i];
        sum2+=b[i];
    }
    for(int i=0;i<s3;i++){
        cin>>c[i];
        sum3+=c[i];
    }
    for(int i=0;i<s4;i++){
        cin>>d[i];
        sum4+=d[i];
    }
    int cnt=ans(a,sum1,s1)+ans(b,sum2,s2)+ans(c,sum3,s3)+ans(d,sum4,s4);
    cout<<cnt;
    return 0;
}