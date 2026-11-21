#include <iostream>
#include <string>
using namespace std;
int find(string s) {
    int l = s.length();
    int* next = new int[l + 1];
    next[0] = -1;
    int i = 0, j = -1;
    while (i < l) {
        if (j == -1 || s[i] == s[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    int maxl = next[l];
    int cy = l - maxl;
    delete[] next;
    if (cy == l) {
        return l;
    }
    if (l % cy == 0) {
        return 0;
    }
    return cy - l % cy;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << find(s) << endl;
    }
    return 0;
}