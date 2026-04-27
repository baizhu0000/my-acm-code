#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int target=stoi(s);
        int r=sqrt(target);
        bool pd=false;
        if(r*r==target){
            for(int i=0;i<=r;i++){
                int b=r-i;
                int ans=(i+b)*(i+b);
                string a;
                if(ans<10){
                    a="000"+to_string(ans);
                }else if(ans<100){
                    a="00"+to_string(ans);
                }else if(ans<1000){
                    a="0"+to_string(ans);
                }else{
                    a=to_string(ans);
                }
                if(a==s){
                    cout<<i<<" "<<b<<endl;
                    pd=true;
                    break;
                }
            }
        }
        if(!pd){
            cout<<-1<<endl;
        }
        
    }

    return 0;
}