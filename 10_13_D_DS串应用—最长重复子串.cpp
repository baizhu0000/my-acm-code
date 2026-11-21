#include <iostream>
#include <string>
using namespace std;
int find(string s) {
    int len = s.length();
    for (int l = len / 2; l >= 1; l--) {
        for (int i = 0; i + l <= len; i++) {
            string sub = s.substr(i, l);
            for (int j = i + l; j + l <= len; j++) {
                if (s.substr(j, l) == sub) {
                    return l;
                }
            }
        }
    }
    return -1;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << find(s) << endl;
    }
}