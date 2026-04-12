#include <iostream>
using namespace std;
int n,cnt=0;
int a[15]={0},jie[3][15];
bool used[15]={false},dui1[30]={false},dui2[30]={false};
void solve(int x){
    if(x==n+1){
        cnt++;
        if(cnt<=3){
            for(int i=1;i<=n;i++){
                jie[cnt-1][i]=a[i];
            }
        }
        return ;
    }
    
    for(int i=1;i<=n;i++){
        if(!used[i]&&!dui1[x-i+n]&&!dui2[x+i]){
            a[x]=i;
            used[i]=true;
            dui1[x-i+n]=true;
            dui2[x+i]=true;
            solve(x+1);
            used[i]=false;
            dui1[x-i+n]=false;
            dui2[x+i]=false;
        }
    }
}
int main()
{
    cin>>n;
    solve(1);
    if(cnt<3){
        for(int i=0;i<cnt;i++){
            for(int j=1;j<=n;j++){
                cout<<jie[i][j]<<" ";
            }
            cout<<endl;
        }
    }else{
        for(int i=0;i<3;i++){
            for(int j=1;j<=n;j++){
                cout<<jie[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    cout<<cnt<<endl;

    return 0;
}