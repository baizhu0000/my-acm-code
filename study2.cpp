#include <iostream>
#include <iomanip>
using namespace std;
class Time;
class Date
{
private:
    int year, month, day;

public:
    Date(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    friend void display(const Date &d, const Time &t);
};
class Time
{
private:
    int h, min, s;

public:
    Time(int hh, int m, int ss)
    {
        h = hh;
        min = m;
        s = ss;
    }
    friend void display(const Date &d, const Time &t);
};
void display(const Date &d, const Time &t)
{
    cout << setfill('0');
    cout << setw(4) << d.year << "-"
         << setw(2) << d.month << "-"
         << setw(2) << d.day << " ";
    cout << setw(2) << t.h << ":"
         << setw(2) << t.min << ":"
         << setw(2) << t.s << endl;
}
int main()
{
    int t;
    cin >> t;
    int y, mon, dy;
    int hh, m, ss;
    while (t--)
    {
        cin >> y >> mon >> dy;
        cin >> hh >> m >> ss;
        Date d(y, mon, dy);
        Time t(hh, m, ss);
        display(d, t);
    }
    return 0;
}