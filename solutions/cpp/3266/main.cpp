#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string A, B; cin >> A >> B;
    int K; cin >> K;
    int N = (int)A.size(), M = (int)B.size();
    vector<vector<int>> DP(N + 1, vector<int>(M + 1));

    function<int(int, int)> cal = [&](int a, int b) -> int {
        if(a < 0 || b < 0) return K;
        return abs(A[a] - B[b]);
    };
    for(int i = 0; i <= N; ++i) {
        for(int j = 0; j <= M; ++j) {
            if(i == 0 && j == 0) continue;
            int &ret = DP[i][j];
            ret = INT_MAX;
            if(i > 0 && j > 0) {
                ret = min(ret, DP[i - 1][j - 1] + cal(i - 1, j - 1));
            }
            if(i > 0) {
                ret = min(ret, DP[i - 1][j] + cal(i - 1, -1));
            }
            if(j > 0) {
                ret = min(ret, DP[i][j - 1] + cal(-1, j - 1));
            }
        }
    }
    cout << DP[N][M];

    return 0;
}