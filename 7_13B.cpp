#include <iostream>
#include <string>
using namespace std;
class js {
   protected:
    int en, wi, vi;

   public:
    js(int e, int w, int v) : en(e), wi(w), vi(v) {}
    void print() {
        cout << "硬度" << en << "--重量" << wi << "--体积" << vi << endl;
    }
    friend js operator+(const js& a, const js& b) {
        int nen = a.en + b.en;
        int nwi = a.wi + b.wi;
        int nvi = a.vi + b.vi;
        return js(nen, nwi, nvi);
    }
    friend js operator*(const js& a, int n) {
        int nen = a.en;
        int nwi = a.wi;
        int nvi = a.vi * n;
        return js(nen, nwi, nvi);
    }
    friend js operator*(int n, const js& a) {
        return a * n;
    }
    js& operator++() {
        en++;
        wi += (wi * 0.1);
        vi += (vi * 0.1);
        return *this;
    }
    js& operator--(int) {
        js temp = *this;
        en--;
        wi -= (wi * 0.1);
        vi -= (vi * 0.1);
        return temp;
    }
};
int main() {
    int e1, w1, v1;
    int e2, w2, v2;
    int n;
    cin >> e1 >> w1 >> v1;
    cin >> e2 >> w2 >> v2;
    cin >> n;
    js a(e1, w1, v1);
    js b(e2, w2, v2);
    js c = a + b;
    c.print();
    js d = a * n;
    d.print();
    ++a;
    a.print();
    b--;
    b.print();
    return 0;
}