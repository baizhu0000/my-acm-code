#include <iostream>
#include <cstdio>
using namespace std;
int n,t;
void qsort(double a[],int m[],int l,int r){
    int i=l,j=r,temp;
    double flag=a[(l+r)/2];
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
            temp=m[i];
            m[i]=m[j];
            m[j]=temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(i<r){
        qsort(a,m,i,r);
    }
    if(l<j){
        qsort(a,m,l,j);
    }
}
int main()
{
    cin>>n>>t;
    int m[n],v;
    double b[n];//记录每份的没质量的价值；
    for(int i=0;i<n;i++){
        cin>>m[i]>>v;
        b[i]=v/m[i]*1.0;
    }
    qsort(b,m,0,n-1);
    double cnt=0;
    int num=n-1;
    for(num=n-1;num>=0;num--){
        if(t>=m[num]){
            cnt+=m[num]*b[num];
            t-=m[num];
        }else{
            break;
        }
    }
    if(t==0){
        printf("%.2f",cnt);
    }else{
        cnt+=t*b[num];
        printf("%.2f",cnt);
    }
    return 0;
}