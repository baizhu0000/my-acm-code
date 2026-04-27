#include<stdio.h>
#include<math.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    char a[80],b[80];
    scanf("%s",a);
    for(int i=1;i<n;i++){
        scanf("%s",b);
        int x=strlen(a);
        int y=strlen(b);
        if(x<y){
            char temp[80];
            strcpy(temp,a);
            strcpy(a,b);
            strcpy(b,temp);
        }
    }   
    printf("The longest is: %s",a);
    return 0;
}