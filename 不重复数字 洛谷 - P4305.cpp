#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    int t;
    cin>>t;
    unordered_set<int>s;
    while(t--){
        s.clear();
        int n;
        cin>>n;
        int a;
        for(int i=0;i<n;i++){
            cin>>a;
            if(!s.count(a)){
                cout<<a<<" ";
                s.insert(a);
            }
        }
        cout<<endl;
    }

    return 0;
}