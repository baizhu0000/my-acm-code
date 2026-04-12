#include <iostream>
#include <cmath>
#include<string>
#include <algorithm>
using namespace std;
bool pdzhi(int n){
    if(n<2){
        return false;
    }else{
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}
void hui(int a,int b){
    if(a<=2&&2<=b) cout<<2<<endl;
    if(a<=3&&3<=b) cout<<3<<endl;
    if (a <= 5 && 5 <= b) cout << 5 << endl;
    if (a <= 7 && 7 <= b) cout << 7 << endl;
    if(a<=11&&11<=b&&pdzhi(11)){
        cout<<11<<endl;
    }

    for(int d=3;d<=7;d+=2){
        int halen=(d+1)/2;
        int start=1;
        for(int i=1;i<halen;i++){
            start*=10;
        }
        int end=start*10-1;
        for(int h=start;h<=end;h++){
            string s=to_string(h);
            string rev=s.substr(0,halen-1);
            reverse(rev.begin(),rev.end());
            string str=s+rev;
            int x=stoi(str);
            if(x>b){
                if(h==start){
                    return;
                }
                break;
            }
            if(x>=a&&pdzhi(x)){
                cout<<x<<endl;
            }
        }
    }
}
int main()
{
    int a,b;
    cin>>a>>b;
    hui(a,b);
    return 0;
}