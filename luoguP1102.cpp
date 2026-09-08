#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long long c;
    cin>>n>>c;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    long long ans=0;
    int j=0,k=0;
    for(int i=0;i<n;i++){
        while(j<n&&a[j]<a[i]+c){
            j++;
        }
        while(k<n&&a[k]<=a[i]+c){
            k++;
        }
        ans+=k-j;
    }
    cout<<ans<<endl;

    return 0;
}