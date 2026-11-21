#include <iostream>
using namespace std;

const int maxn = 15;
class graph {
   public:
    int matrix[maxn][maxn];
    int indeg[maxn];
    bool vis[maxn];
    int n;

    void build() {
        cin >> n;
        int len;
        cin >> len;
        for (int i = 0; i < n; i++) {
            vis[i] = false;
            indeg[i] = 0;
            for (int j = 0; j < n; j++) {
                matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < len; i++) {
            int u, v;
            cin >> u >> v;
            matrix[v][u] = 1;
            indeg[u]++;
        }
    }

    bool solve() {
        for (int k = 0; k < n; k++) {
            int dot = -1;
            for (int j = 0; j < n; j++) {
                if (vis[j]) {
                    continue;
                }
                if (indeg[j] == 0) {
                    dot = j;
                    break;
                }
            }
            if (dot == -1) {
                return false;
            }
            vis[dot] = true;
            for (int j = 0; j < n; j++) {
                if (matrix[dot][j] != 0) {
                    matrix[dot][j] = 0;
                    indeg[j]--;
                }
            }
        }
        return true;
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        graph g;
        g.build();
        bool ans = g.solve();
        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}