#include <iostream>
using namespace std;

const int MOD = 10000;
int f[1000010], g[1000010];

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 2) {
        cout << 2 << endl;
        return 0;
    }
    f[0] = 1;  
    f[1] = 1;
    f[2] = 2;
    g[0] = 0;
    g[1] = 0;
    g[2] = 1;
    
    for (int i = 3; i <= n; i++) {
        g[i] = (g[i-1] + f[i-2]) % MOD;
        f[i] = (f[i-1] + f[i-2] + 2 * g[i-1]) % MOD;
    }
    
    cout << f[n] ;
    return 0;
}