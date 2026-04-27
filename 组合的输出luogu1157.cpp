#include <iostream>
#include <iomanip>
using namespace std;
int n,r;
int result[25];
void solve(int depth,int start){
    if(depth==r){
        for(int i=0;i<r;i++){
            cout<<setw(3)<<result[i];
        }
        cout<<endl;
        return ;
    }
    for(int i=start;i<=n;i++){
        result[depth]=i;
        solve(depth+1,i+1);
    }
}
int main()
{
    cin>>n>>r;
    solve(0,1);

    return 0;
}
