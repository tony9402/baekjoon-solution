#include<bits/stdc++.h>

using namespace std;

const int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
const int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};

string B[500];

int calculate(int y, int x, int N) {
    int ret = 0;
    for (int k = 0; k < 8; ++k) {
        int cur = 0;
        for (int step = 1; ; ++step) {
            int next_y = y + step * dy[k];
            int next_x = x + step * dx[k];
            if (0 > next_y || next_y >= N || 0 > next_x || next_x >= N \
                    || B[next_y][next_x] == '.') {
                cur = 0;
                break;
            }
            if (B[next_y][next_x] == 'B') break;
            ++cur;
        }
        ret += cur;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; ++i) cin >> B[i];

    int ansy = -1, ansx = -1, mx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (B[i][j] != '.') continue;
            int cur = calculate(i, j, N);
            if (cur > mx) {
                mx = cur;
                ansy = i;
                ansx = j;
            }
        }
    }
    if (mx == 0) cout << "PASS";
    else cout << ansx << ' ' << ansy << '\n' << mx;

    return 0;
}
