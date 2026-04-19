#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    deque<int> dq;
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&a[dq.back()]>a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k){
            while(!dq.empty()&&dq.front()<=i-k){
               dq.pop_front();
            }
            cout<<a[dq.front()]<<" ";
        }
    }
    cout<<endl;
    while(!dq.empty()){
        dq.pop_back();
    }
    for(int i=1;i<=n;i++){
        while(!dq.empty()&&a[dq.back()]<a[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k){
            while(!dq.empty()&&dq.front()<=i-k){
                dq.pop_front();
            }
            cout<<a[dq.front()]<<" ";
        }
    }

    return 0;
}