#include<iostream>
using namespace std;
int main()
{
    int year;
    cin >> year;
    bool p1,p2;
    p1=(year%4==0)&&(year%100!=0);
    p2=year%400==0;
    cout <<(p1||p2)<<endl;

    return 0;
}