#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        stack<int>st;
        int idx1=0,idx2=0;
        while(idx1<n){
            st.push(a[idx1]);
            idx1++;
            while(st.size()&&st.top()==b[idx2]){
                st.pop();
                idx2++;
            }
        }
        if(idx2==n){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }

    return 0;
}