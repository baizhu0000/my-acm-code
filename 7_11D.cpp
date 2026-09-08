#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
class Cset {
   private:
    int n;
    int* data;

   public:
    Cset(int g, int* arr) {
        n = g;
        data = new int[g];
        for (int i = 0; i < n; i++) {
            data[i] = arr[i];
        }
    }
    Cset(const Cset& o) : n(o.n) {
        data = new int[o.n];
        for (int i = 0; i < n; i++) {
            data[i] = o.data[i];
        }
    }
    Cset& operator=(const Cset& o) {
        if (this != &o) {
            delete[] data;
            n = o.n;
            data = new int[o.n];
            for (int i = 0; i < n; i++) {
                data[i] = o.data[i];
            }
        }
        return *this;
    }
    ~Cset() {
        delete[] data;
    }
    friend Cset operator+(const Cset& a, const Cset& b) {
        int* k = new int[a.n + b.n];
        int p = a.n;
        for (int i = 0; i < a.n; i++) {
            k[i] = a.data[i];
        }
        for (int i = 0; i < b.n; i++) {
            bool pd = false;
            for (int j = 0; j < a.n; j++) {
                if (b.data[i] == a.data[j]) {
                    pd = true;
                    break;
                }
            }
            if (!pd) {
                k[p++] = b.data[i];
            }
        }
        Cset c(p, k);
        delete[] k;
        return c;
    }
    friend Cset operator*(const Cset& a, const Cset& b) {
        int* k = new int[min(a.n, b.n)];
        int p = 0;
        for (int i = 0; i < a.n; i++) {
            for (int j = 0; j < b.n; j++) {
                if (a.data[i] == b.data[j]) {
                    k[p++] = a.data[i];
                    break;
                }
            }
        }
        Cset c(p, k);
        delete[] k;
        return c;
    }

    friend Cset operator-(const Cset& a, const Cset& b) {
        int* k = new int[a.n];
        int p = 0;
        for (int i = 0; i < a.n; i++) {
            bool pd = false;
            for (int j = 0; j < b.n; j++) {
                if (a.data[i] == b.data[j]) {
                    pd = true;
                    break;
                }
            }
            if (!pd) {
                k[p++] = a.data[i];
            }
        }
        Cset c(p, k);
        delete[] k;
        return c;
    }
    void print() const {
        for (int i = 0; i < n; i++) {
            cout << data[i];
            if (i != n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int na;
        cin >> na;
        int arra[na];
        for (int i = 0; i < na; i++) {
            cin >> arra[i];
        }
        int nb;
        cin >> nb;
        int arrb[nb];
        for (int i = 0; i < nb; i++) {
            cin >> arrb[i];
        }
        Cset a(na, arra);
        Cset b(nb, arrb);
        cout << "A:";
        a.print();
        cout << "B:";
        b.print();
        cout << "A+B:";
        (a + b).print();
        cout << "A*B:";
        (a * b).print();
        cout << "(A-B)+(B-A):";
        ((a - b) + (b - a)).print();
        cout << endl;
    }
    return 0;
}