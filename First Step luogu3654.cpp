#include <iostream>
using namespace std;
int main()
{
    int r,c,k;
    cin>>r>>c>>k;
    char a[r][c];
    int cnt=0;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    if(k==1){
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(a[i][j]=='.'){
                    cnt++;
                }
            }
        }
    }else{
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i+k-1<r){
                    bool pd=true;
                    for(int l=0;l<k;l++){
                        if(a[i+l][j]=='#'){
                            pd=false;
                            break;
                        }
                    }
                    if(pd){
                        cnt++;
                    }
                }
                if(j+k-1<c){
                    bool pd=true;
                    for(int l=0;l<k;l++){
                        if(a[i][j+l]=='#'){
                            pd=false;
                            break;
                        }
                    }
                    if(pd){
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}