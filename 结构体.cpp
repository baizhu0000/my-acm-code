//结构体的作用：自定义数据类型，打包一些不同类型的数据
//cpp支持在结构体内部写函数
#include <iostream>
#include <string>
using namespace std;
struct name//name相当于类型名，类似于int double
{
    string s;
    char c;
    int a,b;
    int sum(){
        return a+b;
    }
    /* data */
};//也可以定义在这里a[100];
//定义数组
name num[100];
int main()
{
    cin>>num[0].a>>num[0].b;//输入数据
    cout<<num[0].sum();
    return 0;
}