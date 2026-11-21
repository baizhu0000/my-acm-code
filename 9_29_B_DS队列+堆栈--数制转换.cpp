#include <iostream>
#include <queue>
#include <stack>
using namespace std;
char digitToChar(int d) {
    if (d < 10)
        return '0' + d;
    else
        return 'A' + (d - 10);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        stack<int> in;
        queue<int> dou;
        double n;
        int k;
        cin >> n >> k;

        int intpart = (int)n;
        double doupart = n - intpart;

        if (intpart == 0) {
            in.push(0);
        } else {
            while (intpart > 0) {
                int d = intpart % k;
                in.push(d);
                intpart /= k;
            }
        }

        for (int i = 0; i < 3; i++) {
            doupart *= k;
            int d = (int)doupart;
            dou.push(d);
            doupart -= d;
        }

        while (!in.empty()) {
            cout << digitToChar(in.top());
            in.pop();
        }
        cout << ".";

        while (!dou.empty()) {
            cout << digitToChar(dou.front());
            dou.pop();
        }
        cout << endl;
    }
    return 0;
}