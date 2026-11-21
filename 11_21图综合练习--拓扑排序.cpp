#include <iostream>
using namespace std;

const int maxn = 15;
class graph {
   public:
    int matrix[maxn][maxn];
    bool vis[maxn];
    int v;

    void build() {
        cin >> v;
        for (int i = 0; i < v; i++) {
            vis[i] = false;
            for (int j = 0; j < v; j++) {
                cin >> matrix[i][j];
            }
        }
    }

    void solve() {
        for (int i = 0; i < v; i++) {
            int dot = -1;
            for (int j = 0; j < v; j++) {
                if (vis[j]) continue;
                int indeg = 0;
                for (int k = 0; k < v; k++) {
                    if (matrix[k][j] != 0) indeg++;
                }
                if (indeg == 0) {
                    dot = j;
                    vis[j] = true;
                    break;
                }
            }
            if (dot == -1) break;
            cout << dot << " ";
            for (int j = 0; j < v; j++) {
                matrix[dot][j] = 0;
            }
        }
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        graph g;
        g.build();
        g.solve();
    }
    return 0;
}