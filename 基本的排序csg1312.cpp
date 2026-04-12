#include <iostream>
using namespace std;
void qsort(int a[],int l,int r){
    int i=l,j=r,flag=a[(l+r)/2],temp;
    do{
        while(a[i]<flag){
            i++;
        }
        while(a[j]>flag){
            j--;
        }
        if(i<=j){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(i<r){
        qsort(a,i,r);
    }
    if(j>l){
        qsort(a,l,j);
    }
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    qsort(a,0,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}