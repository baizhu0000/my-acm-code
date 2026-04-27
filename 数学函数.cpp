#include <cstdio>
#include <cmath>
using namespace std;
int main()
{
    double a,b;
    scanf("%lf %lf", &a, &b);
    double c,d;
    c=sin(a);//三角函数
    d=cos(b);
    printf("%f %d",c,d);
    double f=exp(2);//e的x次方，即e的二次方
    double g=log(10);//返回自然对数
    int h=pow(2,3);//返回2的3次方
    double j=fabs(-1);//绝对值
    double k=ceil(2.1);//向上取整
    double l=floor(2.9);//向下取整
    printf("%f %f %d %f %f %f",f,g,h,j,k,l);
    return 0;
}