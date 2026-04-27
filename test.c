#include <stdio.h>

int main()
{
    int i;
    int sum=0;
    for( i=0;i<12;i++ ){
        sum+=i;
    }
    printf("%d",sum);
    return 0;
}