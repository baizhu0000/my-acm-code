#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Bigint
{
    vector<int>a;
    Bigint(int x=0){
        if(x==0){
            a.push_back(0);
        }else{
            while(x>0){
                a.push_back(x%10);
                x/=10;
            }
        }
    }
    Bigint operator+(Bigint& x){
        Bigint res;
        res.a.clear();
        int temp=0;
        int maxlen=max(a.size(),x.a.size());
        for(int i=0;i<maxlen;i++){
            int sum=temp;
            if(i<a.size()){
                sum+=a[i];
            }
            if(i<x.a.size()){
                sum+=x.a[i];
            }
            res.a.push_back(sum%10);
            temp=sum/10;
        }
        if(temp>0){
            res.a.push_back(temp);
        } 
        return res;
    }
    void print(){
        for(int i=a.size()-1;i>=0;i--){
            cout<<a[i];
        }
    }
};

Bigint f[5010];
int main()
{
    int n;
    cin>>n;
    if(n<=2){
        cout<<n;
    }else{
        f[1]=Bigint(1);
        f[2]=Bigint(2);
        for(int i=3;i<=n;i++){
            f[i]=f[i-1]+f[i-2];
        }
        f[n].print();
    }
    return 0;
}