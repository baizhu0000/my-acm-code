#include <iostream>
using namespace std;
void qsort(int a[],int l,int r){
    int i=l,j=r,flag=a[(l+r)/2],tmp;
    do{
        while(a[i]<flag){
            i++;
        }
        while(a[j]>flag){
            j--;
        }
        if(i<=j){
            tmp=a[i];
            a[i]=a[j];
            a[j]=tmp;
            i++;
            j--;
        }
    }while(i<=j);
    if(l<j){
        qsort(a,l,j);
    }
    if(i<r){
        qsort(a,i,r);
    }
}
void solve(int a[],int sum){
    
}
int main()
{
    int s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    int sum1=0,sum2=0,sum3=0,sum4=0;
    int a[s1],b[s2],c[s3],d[s4];
    for(int i=0;i<s1;i++){
        cin>>a[i];
        sum1+=a[i];
    }
    qsort(a,0,s1-1);
    for(int i=0;i<s2;i++){
        cin>>b[i];
        sum2+=b[i];
    }
    qsort(b,0,s2-1);
    for(int i=0;i<s3;i++){
        cin>>c[i];
        sum3+=c[i];
    }
    qsort(c,0,s3-1);
    for(int i=0;i<s4;i++){
        cin>>d[i];
        sum4+=d[i];
    }
    qsort(d,0,s4-1);
    
    return 0;
}