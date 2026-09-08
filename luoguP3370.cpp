#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    unordered_set<string>s;
    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        s.insert(x);
    }
    cout<<s.size()<<endl;
    return 0;
}