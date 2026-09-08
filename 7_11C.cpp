#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class CDate {
   protected:
    int year, month, day;
    bool pd(int y) const { return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0); }
    int getdaysinmonth(int y, int m) const {
        int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (m == 2 && pd(y)) return 29;
        return days[m];
    }
    int totaldays(int y, int m, int d) const {
        int total = 0;
        for (int i = 1; i < y; i++) {
            if (!pd(i)) {
                total += 365;
            } else {
                total += 366;
            }
        }
        for (int i = 1; i < m; i++) {
            total += getdaysinmonth(y, i);
        }
        total += d;
        return total;
    }
    int daysbetween(int y1, int m1, int d1, int y2, int m2, int d2) const {
        int days1 = totaldays(y1, m1, d1);
        int days2 = totaldays(y2, m2, d2);
        return abs(days1 - days2);
    }

   public:
    CDate(int y, int m, int d) : year(y), month(m), day(d) {}
    int operator-(const CDate& o) const {
        return daysbetween(year, month, day, o.year, o.month, o.day);
    }
    bool isBefore(const CDate& o) const {
        if (year != o.year) return year < o.year;
        if (month != o.month) return month < o.month;
        return day < o.day;
    }
};
class Pet {
   protected:
    string name;
    float length;
    float weight;
    CDate current;

   public:
    Pet(string n, float l, float w, int y, int m, int d) : current(y, m, d), name(n), length(l), weight(w) {}

    virtual void display(CDate day) = 0;
    virtual ~Pet() {}
};
class Cat : public Pet {
   public:
    Cat(string n, float l, float w, int y, int m, int d) : Pet(n, l, w, y, m, d) {}
    void display(CDate d) {
        int days = d - current;
        if (days < 0) {
            cout << "error" << endl;
            return;
        }
        float newl = length + days * 0.1;
        float neww = weight + days * 0.2;
        cout << name << " after " << days << " day: ";
        cout << "length=" << fixed << setprecision(2) << newl << ",";
        cout << "weight=" << fixed << setprecision(2) << neww << endl;
    }
};
class Dog : public Pet {
   public:
    Dog(string n, float l, float w, int y, int m, int d) : Pet(n, l, w, y, m, d) {}
    void display(CDate d) {
        int days = d - current;
        if (days < 0) {
            cout << "error" << endl;
            return;
        }
        float newl = length + days * 0.2;
        float neww = weight + days * 0.1;
        cout << name << " after " << days << " day: ";
        cout << "length=" << fixed << setprecision(2) << newl << ",";
        cout << "weight=" << fixed << setprecision(2) << neww << endl;
    }
};
int main() {
    int t;
    cin >> t;
    int sy, sm, sd;
    cin >> sy >> sm >> sd;
    CDate start(sy, sm, sd);
    Pet* pt = NULL;
    while (t--) {
        int type;
        string name;
        float l, w;
        int y, m, d;
        cin >> type >> name >> l >> w >> y >> m >> d;
        CDate petDate(y, m, d);
        if (petDate.isBefore(start)) {
            cout << "error" << endl;
            continue;
        }
        if (type == 1) {
            pt = new Cat(name, l, w, y, m, d);
        } else if (type == 2) {
            pt = new Dog(name, l, w, y, m, d);
        }

        pt->display(start);
        delete pt;
        pt = NULL;
    }
    return 0;
}