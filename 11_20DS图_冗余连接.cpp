#include <iostream>
using namespace std;

const int MAXN = 1005;
int parent[MAXN];

int findRoot(int x) {
    while (x != parent[x]) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

void unionSet(int x, int y) {
    int rx = findRoot(x), ry = findRoot(y);
    if (rx != ry) parent[rx] = ry;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) parent[i] = i;

        int ansA = -1, ansB = -1;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (findRoot(a) == findRoot(b)) {
                if (!found) {
                    ansA = a;
                    ansB = b;
                    found = true;
                }
            } else {
                unionSet(a, b);
            }
        }
        cout << ansA << " " << ansB << endl;
    }
    return 0;
}