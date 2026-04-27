#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        a[i]=i+1;
    }
    do{
        for(int i=0;i<n;i++){
            cout<<setw(5)<<a[i];
        }
        cout<<endl;
    }while(next_permutation(a+0,a+n));
    return 0;
}