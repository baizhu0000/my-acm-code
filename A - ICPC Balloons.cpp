#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt[26]={0};
        int ans=0;
        for(int i=0;i<n;i++){
            cnt[(int)(s[i]-'A')]++;
            if(cnt[(int)s[i]-'A']==1){
                ans+=2;
            }else{
                ans+=1;
            }
        }
        cout<<ans<<endl;
    }


    return 0;
}