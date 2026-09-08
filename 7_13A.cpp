#include <iostream>
#include <string>
using namespace std;
class Member {
   protected:
    int id;
    string name;
    int cre;

   public:
    Member() : id(0), name(""), cre(0) {}
    Member(int i, string n, int c) : id(i), name(n), cre(c) {}
    virtual void add(int x) {
        cre += x;
    }
    virtual int exchange(int x) {
        int ans = x / 100;
        cre -= (ans * 100);
        return ans;
    }
    virtual void print() {
        cout << "普通会员" << id << "--" << name << "--" << cre << endl;
    }
    virtual ~Member() {}
};
class Vip : public Member {
   private:
    int ad;
    int ex;

   public:
    Vip(int i, string n, int c, int a, int e) : Member(i, n, c), ad(a), ex(e) {}
    virtual void add(int x) {
        cre += x * ad;
    }
    virtual int exchange(int x) {
        int ans = x / ex;
        cre -= (ans * ex);
        return ans;
    }
    virtual void print() {
        cout << "贵宾会员" << id << "--" << name << "--" << cre << endl;
    }
};
int main() {
    Member* p;
    int id1, c1;
    string n1;
    cin >> id1 >> n1 >> c1;
    Member a(id1, n1, c1);
    int x1, x2;
    cin >> x1 >> x2;
    p = &a;
    p->add(x1);
    p->exchange(x2);
    p->print();
    int id2, c2;
    string n2;
    int ad, ex;
    cin >> id2 >> n2 >> c2 >> ad >> ex;
    Vip b(id2, n2, c2, ad, ex);
    int x3, x4;
    cin >> x3 >> x4;
    p = &b;
    p->add(x3);
    p->exchange(x4);
    p->print();
    return 0;
}