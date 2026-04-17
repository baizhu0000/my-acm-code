#include <iostream>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    char a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    int cntw[n]={0},cntb[n]={0},cntr[n]={0};//每行涂成某种颜色的代价
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='W'){
                cntw[i]++;
            }else if(a[i][j]=='B'){
                cntb[i]++;
            }else if(a[i][j]=='R'){
                cntr[i]++;
            }
        }
        cntw[i]=m-cntw[i];
        cntb[i]=m-cntb[i];
        cntr[i]=m-cntr[i];
    }
    int pw[n]={0},pb[n]={0},pr[n]={0};//0到每行涂成某种颜色所需要的格子数
    pw[0]=cntw[0];
    pb[0]=cntb[0];
    pr[0]=cntb[0];
    for(int i=1;i<n;i++){
       pw[i]=pw[i-1]+cntw[i];
       pb[i]=pb[i-1]+cntb[i];
       pr[i]=pr[i-1]+cntr[i];
    }
    int ans=n*m;
    for(int i=0;i<=n-3;i++){
        for(int j=i+1;j<=n-2;j++){
           int cost=pw[i]+pb[j]-pb[i]+pr[n-1]-pr[j];
           if(cost<ans){
            ans=cost;
           } 
        }
    }
    cout<<ans;
    return 0;
}