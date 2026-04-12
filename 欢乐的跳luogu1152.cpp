#include <iostream>
#include <cmath>
using namespace std;
void qsort(int cha[],int l,int r){
    int i=l,j=r,flag=cha[(l+r)/2],temp;
    do{
        while(cha[i]<flag){
            i++;
        }
        while(cha[j]>flag){
            j--;
        }
        if(i<=j){
            temp=cha[i];
            cha[i]=cha[j];
            cha[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(i<r){
        qsort(cha,i,r);
    }
    if(j>l){
        qsort(cha,l,j);
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
    int cha[n-1];
    for(int i=0;i<n-1;i++){
        cha[i]=abs(a[i]-a[i+1]);
    }
    qsort(cha,0,n-2);

    int pd=1;
    for(int i=1;i<n-1;i++){
        if(cha[i]==cha[i-1]){
            continue;
        }
        if(cha[i]-cha[i-1]!=1){
            pd=0;
            break;
        }
    }
    if(pd==1){
        cout<<"Jolly";
    }else{
        cout<<"Not jolly";
    }
    return 0;
}