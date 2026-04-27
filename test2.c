#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int t;
    scanf("%d",&t);
    int b[t];
    for(int i=0;i<t;i++){
        scanf("%d",&b[i]);
    }
    int c[n+t],len=0;
    for(int i=0;i<n;i++){
        int pd=1;
        for(int j=0;j<t;j++){
            if(a[i]==b[j]){
                pd=0;
                break;
            }
        }
        if(pd==1){
            c[len]=a[i];
            len++;
        }
    }
    for(int j=0;j<t;j++){
        int pd=1;
        for(int i=0;i<n;i++){
            if(a[i]==b[j]){
                pd=0;
                break;
            }
        }
        if(pd==1){
            c[len]=b[j];
            len++;
        }
    }
    for(int i=0;i<len;i++){
        int pd=1;
        for(int j=0;j<i;j++){
            if(a[j]==a[i]){
                pd=0;
                break;
            }
        }
        if(pd==0){
            continue;
        }else{
            printf("%d",c[i]);
        }
    }
    return 0;
}