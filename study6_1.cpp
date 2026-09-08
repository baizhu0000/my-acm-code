#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Group {
public:
    virtual int add(int x, int y) = 0;
    virtual int sub(int x, int y) = 0;
    virtual ~Group() {}
};  
class Groupa : public Group {
public:
    int add(int x, int y) override {
        return x + y;
    }
    int sub(int x, int y) override {
        return x - y;
    }
}; 
class Groupb : public Group {
public:
    int add(int x, int y) override {
        return x + y;
    }
    int sub(int x, int y) override {
    int res = 0;
    int d = 1;
    int tx = x, ty = y;
    int borrow = 0;  // 借位标记（但第二类学生只借位，不减高位）
    while (tx > 0 || ty > 0) {
        int xd = tx % 10;
        int yd = ty % 10;
        int diff;
        if (xd < yd) {
            diff = xd + 10 - yd;  
        } else {
            diff = xd - yd;
        }
        res += diff * d;
        tx /= 10;
        ty /= 10;
        d *= 10;
    }
    return res;
}
};
class Groupc : public Group {
public:
    int add(int x, int y) override {
        int res = 0;
        int d = 1;
        int tx = x, ty = y;
        while (tx > 0 || ty > 0) {
            int xd = tx % 10;
            int yd = ty % 10;
            int sum = (xd + yd) % 10;  
            res += sum * d;
            tx /= 10;
            ty /= 10;
            d *= 10;
        }
        return res;
    }
    int sub(int x, int y) override {
        int res = 0;
        int d = 1;
        int tx = x, ty = y;
        while (tx > 0 || ty > 0) {
            int xd = tx % 10;
            int yd = ty % 10;
            int diff;
            if (xd < yd) {
                diff = xd + 10 - yd;  
            } else {
                diff = xd - yd;
            }
            res += diff * d;
            tx /= 10;
            ty /= 10;
            d *= 10;
        }
        return res;
    }
}; 
int main() {
    int t;
    cin >> t;
    Group* pv = nullptr;
    
    while (t--) {
        int type;
        string exp;
        cin >> type >> exp;
        
        int pos, x, y;
        char op;
        for (pos = 0; pos < exp.length(); pos++) {
            if (exp[pos] == '+' || exp[pos] == '-') {
                op = exp[pos];  
                break;
            }
        }
        
        x = stoi(exp.substr(0, pos));
        y = stoi(exp.substr(pos + 1));
        
        if (type == 1) {
            Groupa a;
            pv = &a;
            if (op == '+') {
                cout << pv->add(x, y) << endl;
            } else {
                cout << pv->sub(x, y) << endl;
            }
        }
        else if (type == 2) {
            Groupb b;
            pv = &b;
            if (op == '+') {
                cout << pv->add(x, y) << endl;
            } else {
                cout << pv->sub(x, y) << endl;
            }
        }
        else if (type == 3) {
            Groupc c;
            pv = &c;
            if (op == '+') {
                cout << pv->add(x, y) << endl;
            } else {
                cout << pv->sub(x, y) << endl;
            }
        }
    }
    
    return 0;
}