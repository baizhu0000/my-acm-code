#include <iostream>
using namespace std;
void re(int a[],int start,int end){
    while(start<end){
        int temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        int j,k;
        for(j=n-2;j>=0;j--){
            if(a[j]<a[j+1]){
                break;
            }
        }
        for(k=n-1;k>j;k--){
            if(a[k]>a[j]){
                int temp=a[k];
                a[k]=a[j];
                a[j]=temp;
                break;
            }
        }
        re(a,j+1,n-1);
    }
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}