#include <stdio.h>
#include <string.h>

int main() {
    char a[105], b[105];
    int x[105],y[105],xd[105],yd[105],c[105],d[105];
    int pd=1;
    scanf("%s%s", a, b);
    int lena=strlen(a);
    int lenb=strlen(b);
    int diana,dianb;
    for(int i=lena-1;i>=0;i--){
        if(a[i]=='.'){
            diana=i;
            break;
        }
    }
    for(int i=lenb-1;i>=0;i--){
        if(b[i]=='.'){
            dianb=i;
            break;
        }
    }
    int max=lena-diana-1;
    if(lenb-dianb-1>lena-diana-1){
        max=lenb-dianb-1;
    }
    for(int i=diana+1;i>=0;i--){
        int x=a[i]-'0';
    }
    return 0;
}