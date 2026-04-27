#include <bits/stdc++.h>
using namespace std;
const int num=5;
int main()
{
    int a[num][num];
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>a[i][j];
        }
    }
    int ma[num],mi[num];
    for(int i=0;i<num;i++){
        ma[i]=a[i][0];
        mi[i]=a[0][i];
        for(int j=1;j<num;j++){
            ma[i]=max(ma[i],a[i][j]);
            mi[i]=min(mi[i],a[j][i]);
        }
    }
    bool pd=0;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            if(a[i][j]==ma[i]&&a[i][j]==mi[j]){
                cout<<i+1<<" "<<j+1<<" "<<a[i][j]<<endl;
                pd=1;
                break;
            }
        }
    }
    if(!pd){
        cout<<"not found"<<endl;
    }
    return 0;
}