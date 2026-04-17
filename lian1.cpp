#include <cstdio>
using namespace std;
int main()
{
    int a,b,c,d,e,f,h1,h2;
    scanf("%d %d %d %d",&a,&b, &c, &d);
    h1=a*60+b;
    h2=c*60+d;
    e=(h2-h1)/60;
    f=(h2-h1)%60;
    printf("%d %d",e,f);

    return 0;
}