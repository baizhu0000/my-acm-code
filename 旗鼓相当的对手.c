#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int ch[n];
    int ma[n];
    int en[n];
    int i;
    for( i=0;i<n;i++ ){
        scanf("%d %d %d", &ch[i], &ma[i], &en[i]);
    }

    int j,k;
    int cnt=0;
    for( j=0;j<n-1;j++ ){
        for(k=j+1;k<n;k++ ){
            if(ch[j]-ch[k]>=-5&&ch[j]-ch[k]<=5){
                if(ma[j]-ma[k]>=-5&&ma[j]-ma[k]<=5){
                    if(en[j]-en[k]>=-5&&en[j]-en[k]<=5){
                        if (ch[j]+en[j]+ma[j]-ch[k]-ma[k]-en[k]>=-10&&ch[j]+en[j]+ma[j]-ch[k]-ma[k]-en[k]<=10)
                        {
                            cnt++;
                        }
                        
                    }
                }
            }
        }
    }

    printf("%d",cnt);

    return 0;
}