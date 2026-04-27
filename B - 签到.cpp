#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m;
    int n;
    cin>>n>>m;
    vector<long long>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int n1=n/2;
    int n2=n-n1;
    vector<long long>sum1;
    vector<long long>sum2;
    for(int s=0;s<(1<<n1);s++){
        long long sum=0;
        for(int i=0;i<n1;i++){
            if(s&(1<<i)){
                sum+=a[i];
            }
        }
        sum1.push_back(sum);
    }
    for(int s=0;s<(1<<n2);s++){
        long long sum=0;
        for(int i=0;i<n2;i++){
            if(s&(1<<i)){
                sum+=a[n1+i];
            }
        }
        sum2.push_back(sum);
    }
    sort(sum2.begin(),sum2.end());
    sort(sum1.begin(),sum1.end());
    long long cnt=0;
    int j=sum2.size()-1;
    for(int i=0;i<sum1.size();i++){
        if(sum1[i]>m){
            break;
        }
        while(j>=0&&sum1[i]+sum2[j]>m){
            j--;
        }
        if(j>=0){
            cnt+=(j+1);
        }
    }
    cout<<cnt;
    return 0;
}