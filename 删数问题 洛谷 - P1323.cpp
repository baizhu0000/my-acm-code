#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int,vector<int>,greater<int>>qp;
    int k,m;
    cin>>k>>m;
    qp.push(1);
    string s="";
    map<int,int>mp;
    mp[1]=1;
    while(k--){
        int x=qp.top();
        qp.pop();
        s+=to_string(x);
        int tem=2*x+1;
        if(!mp[tem]){
            qp.push(tem);
            mp[tem]++;
        }
        tem=4*x+5;
        if(!mp[tem]){
            qp.push(tem);
            mp[tem]++;
        }
    }  
    cout<<s<<endl;
    while(true){
        for(int i=0;i<s.size();i++){
            if(s[i]<s[i+1]){
                s.erase(i,1);
                m--;
                if(!m){
                    cout<<s<<endl;
                    return 0;;
                }
                break;
            }
        }

    }

    return 0;
}