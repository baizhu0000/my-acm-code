#include <algorithm>
#include <iostream>
using namespace std;

struct Term {
    int coef;
    int exp;
};

bool cmp(Term a, Term b) {
    return a.exp < b.exp;
}

int mergeTerms(Term terms[], int n) {
    if (n == 0) return 0;
    sort(terms, terms + n, cmp);
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && terms[i].exp == terms[j - 1].exp) {
            terms[j - 1].coef += terms[i].coef;
        } else {
            terms[j++] = terms[i];
        }
    }
    return j;
}

string formatExp(int exp) {
    if (exp < 0) {
        return "(" + to_string(exp) + ")";
    }
    return to_string(exp);
}

void display(Term terms[], int n) {
    bool first = true;
    bool hasTerm = false;
    for (int i = 0; i < n; i++) {
        if (terms[i].coef == 0) continue;
        hasTerm = true;
        if (!first) {
            cout << " + ";
        }
        first = false;
        if (terms[i].coef < 0) {
            cout << "(" << terms[i].coef << ")";
        } else {
            cout << terms[i].coef;
        }
        if (terms[i].exp != 0) {
            cout << "x^" << formatExp(terms[i].exp);
        }
    }
    if (!hasTerm) {
        cout << "0";
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n;
        Term* p1 = new Term[n];
        for (int i = 0; i < n; i++) {
            cin >> p1[i].coef >> p1[i].exp;
        }
        cin >> m;
        Term* p2 = new Term[m];
        for (int i = 0; i < m; i++) {
            cin >> p2[i].coef >> p2[i].exp;
        }
        int total = n + m;
        Term* result = new Term[total];
        for (int i = 0; i < n; i++) {
            result[i] = p1[i];
        }
        for (int i = 0; i < m; i++) {
            result[n + i] = p2[i];
        }
        sort(p1, p1 + n, cmp);
        sort(p2, p2 + m, cmp);
        display(p1, n);
        display(p2, m);
        int len = mergeTerms(result, total);
        display(result, len);
        delete[] p1;
        delete[] p2;
        delete[] result;
    }
    return 0;
}