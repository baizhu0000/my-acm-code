#include <iostream>
#include <algorithm>
using namespace std;
int wei[10]={0};
int main()
{
    long long a,b,c,x,y,z,cnt=0;
    cin>>a>>b>>c;
    for(int i=1;i<=9;i++){
        wei[i]=i;
    }
    do{
        x=wei[1]*100+wei[2]*10+wei[3];
        y=wei[4]*100+wei[5]*10+wei[6];
        z=wei[7]*100+wei[8]*10+wei[9];
        if(x*b==y*a&&y*c==z*b){
            cout<<x<<" "<<y<<" "<<z<<endl;
            cnt++;
        }
    }while(next_permutation(wei+1,wei+10));
    if(cnt==0){
        cout<<"No!!!";
    }
    return 0;
}