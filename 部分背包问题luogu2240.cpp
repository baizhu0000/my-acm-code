<<<<<<< HEAD
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
=======
#include <cstdio>
#include <algorithm>
using namespace std;
struct coin
{
    int m, v;
} a[110];
bool cmp(coin x, coin y)
{
    return x.v * y.m > y.v * x.m;
}
int main()
{
    int n, t, c, i;
    double ans = 0;
    scanf("%d %d", &n, &t);
    c = t;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a[i].m, &a[i].v);
    }
    sort(a, a + n, cmp);
    for (i = 0; i < n; i++)
    {
        if (a[i].m > c)
        {
            break;
        }
        c -= a[i].m;
        ans += a[i].v;
    }
    if (i < n)
    {
        ans += 1.0 * c / a[i].m * a[i].v;
    }
    printf("%.2f", ans);
>>>>>>> 5c1e01074414ecbf7fc6c3273c687a69729a1c50
    return 0;
}