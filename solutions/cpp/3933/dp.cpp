#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int MAXN = 32768;
    vector<vector<int>> DP(5, vector<int>(MAXN));
    DP[0][0] = 1;
    for (int i = 1; i * i < MAXN; ++i) {
        for (int j = i * i; j < MAXN; ++j) {
            for (int k = 1; k <= 4; ++k) {
                DP[k][j] += DP[k - 1][j - i * i];
            }
        }
    }
    for (int i = 1; i < MAXN; ++i) {
        for (int j = 1; j < 4; ++j) {
            DP[4][i] += DP[j][i];
        }
    }
    while (1) {
        int N; cin >> N;
        if (N == 0) break;
        cout << DP[4][N] << '\n';
    }

    return 0;
}
