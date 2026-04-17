#include <iostream>
using namespace std;
void qsort(int h[],int l,int r){
    int i=l,j=r,flag=h[(l+r)/2],temp;
    do{
        while(h[i]<flag){
            i++;
        }
        while(h[j]>flag){
            j--;
        }
        if(i<=j){
            temp=h[i];
            h[i]=h[j];
            h[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(i<r){
        qsort(h,i,r);
    }
    if(j>l){
        qsort(h,l,j);
    }
}
int main()
{
    int n,b;
    cin>>n>>b;
    int h[n];
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    qsort(h,0,n-1);
    int sum=0,cnt=0;
    for(int i=n-1;i>=0;i--){
        sum+=h[i];
        cnt++;
        if(sum>=b){
            break;
        }
    }
    cout<<cnt;
    return 0;
}