#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int x,cnt[10]={0};
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        while(x>0){
            int t=x%10;
            cnt[t]++;
            x/=10;
        }
    }
    int max=0;
    for(int i=0;i<=9;i++){
        if(cnt[i]>max){
            max=cnt[i];
        }
    }
    printf("%d:",max);
    for(int i=0;i<=9;i++){
        if(cnt[i]==max){
            printf(" %d",i);
        }
    }
    return 0;
}