#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class Cbook {
   private:
    string name, au, pos;
    double price;

   public:
    Cbook() : name(""), au(""), pos(""), price(0) {}
    Cbook(string n, string a, double p, string po) : name(n), au(a), price(p), pos(po) {}
    void input() {
        getline(cin, name, ',');
        getline(cin, au, ',');
        string pricestr;
        getline(cin, pricestr, ',');
        price = stod(pricestr);
        getline(cin, pos);
    }
    void print() {
        cout << name << endl;
        cout << au << endl;
        cout << fixed << setprecision(2) << price << endl;
        cout << pos << endl;
    }
    friend void find(Cbook* book, int n, int& id1, int& id2) {
        if (n == 0) return;
        if (n == 1) {
            id1 = 0;
            id2 = -1;
            return;
        }
        if (book[0].price >= book[1].price) {
            id1 = 0;
            id2 = 1;
        } else {
            id1 = 1;
            id2 = 0;
        }
        for (int i = 2; i < n; i++) {
            if (book[i].price > book[id1].price) {
                id2 = id1;
                id1 = i;
            } else if (book[i].price > book[id2].price) {
                id2 = i;
            }
        }
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        Cbook* books = new Cbook[n];
        for (int i = 0; i < n; i++) {
            books[i].input();
        }
        int id1 = 0, id2 = 0;
        find(books, n, id1, id2);
        books[id1].print();
        cout << endl;
        if (id2 >= 0) {
            books[id2].print();
            cout << endl;
        }
        delete[] books;
        cout << endl;
    }
    return 0;
}