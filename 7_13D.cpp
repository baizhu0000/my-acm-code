#include <iostream>
#include <string>
using namespace std;
class application {
   protected:
    int id, power;

   public:
    application(int i, int p) : id(i), power(p) {}
    virtual void print() const = 0;
    virtual ~application() {}
};
class feng : public application {
   protected:
    int to, fp;

   public:
    feng(int i, int p, int w, int f) : application(i, p), to(w), fp(f) {}
    virtual void tocontrol(int x) {
        to = x;
    }
    virtual void fpcontrol(int x) {
        fp = x;
    }
    virtual ~feng() {}
};
class jia : public application {
   protected:
    double re, ma;

   public:
    jia(int i, int p, int r, int m) : application(i, p), re(r), ma(m) {}
    virtual int warn() const {
        if (re >= ma * 0.5) {
            return 1;
        } else if (re < ma * 0.5 && re >= ma * 0.1) {
            return 2;
        } else {
            return 3;
        }
    }
    virtual ~jia() {}
};
class jiafeng : public feng, public jia {
   private:
    int ing;

   public:
    jiafeng(int i, int p, int w, int f, int r, int m, int in) : feng(i, p, w, f), jia(i, p, r, m), ing(in) {}
    virtual void ingcontrol(int x) {
        if (x < 0 || x > 3) return;
        ing = x;
        if (ing == 1) {
            tocontrol(0);
            fpcontrol(1);
        } else if (ing == 2) {
            tocontrol(1);
            fpcontrol(2);
        } else if (ing == 3) {
            tocontrol(1);
            fpcontrol(3);
        }
    }
    virtual void print() const override {
        cout << "加湿风扇--档位" << ing << endl;
        cout << "编号" << feng::id << "--功率" << feng::power << "W" << endl;
        if (to == 0) {
            cout << "定向吹风--风力";
        } else if (to == 1) {
            cout << "旋转吹风--风力";
        }
        cout << fp << "级" << endl;
        cout << "实际水容量" << re << "升--";
        int t = warn();
        if (t == 1) {
            cout << "水量正常" << endl;
        } else if (t == 2) {
            cout << "水量偏低" << endl;
        } else if (t == 3) {
            cout << "水量不足" << endl;
        }
    }
    virtual ~jiafeng() {}
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int i, p, t, f, r, m, in;
        cin >> i >> p >> t >> f >> r >> m >> in;
        jiafeng jf(i, p, t, f, r, m, in);
        int x;
        cin >> x;
        jf.ingcontrol(x);
        jf.print();
    }
    return 0;
}