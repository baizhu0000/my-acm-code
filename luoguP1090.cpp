#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    priority_queue<int,vector<int>,greater<int>>a;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push(x);
    }
    long long sum=0;
    while(a.size()>1){
        int x=a.top();
        a.pop();
        int y=a.top();
        a.pop();
        int t=x+y;
        sum+=t;
        a.push(t);
    }
    cout<<sum<<endl;
    return 0;
}