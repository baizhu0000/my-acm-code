#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int T[1005], P[1005];
    for (int i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
    }

    int K;
    cin >> K;

    int finish[15] = {0};
    int totalWait = 0, maxWait = 0, lastFinish = 0;

    for (int i = 0; i < N; i++) {
        int win = 0;
        for (int j = 1; j < K; j++) {
            if (finish[j] < finish[win]) win = j;
        }

        int start = (T[i] > finish[win]) ? T[i] : finish[win];
        int wait = start - T[i];
        finish[win] = start + P[i];

        totalWait += wait;
        if (wait > maxWait) maxWait = wait;
        if (finish[win] > lastFinish) lastFinish = finish[win];
    }

    float avg = (float)((double)totalWait / N);
    printf("%.1f %d %d\n", avg, maxWait, lastFinish);

    return 0;
}
