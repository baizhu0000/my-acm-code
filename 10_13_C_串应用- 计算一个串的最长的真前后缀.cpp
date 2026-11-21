#include <iostream>
#include <string>
using namespace std;
string find(string str) {
    int l = str.length();
    if (l <= 1) return "empty";

    int* next = new int[l + 1];
    next[0] = -1;
    int i = 0, j = -1;
    while (i < l) {
        if (j == -1 || str[i] == str[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
    int maxl = next[l];
    delete[] next;
    if (maxl == 0) {
        return "empty";
    } else {
        return str.substr(0, maxl);
    }
}
int main() {
    int n;
    cin >> n;
    while (n--) {
        string str;
        cin >> str;
        cout << find(str) << endl;
    }
    return 0;
}