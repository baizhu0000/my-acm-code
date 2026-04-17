#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int s[n],b[n];//s>*,b>+
    for(int i=0;i<n;i++){
        cin>>s[i]>>b[i];
    }
    int ans=1e9;
    for(int mask=1;mask<(1<<n);mask++){
        int mul=1,sum=0;
        for(int j=0;j<n;j++){
            if((mask>>j)&1){
                mul*=s[j];
                sum+=b[j];
            }
        }
        int temp=abs(mul-sum);
        if(temp<ans){
            ans=temp;
        }
    }
    cout<<ans;
    return 0;
}