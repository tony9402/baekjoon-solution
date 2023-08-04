#include<bits/stdc++.h>

using namespace std;

int cnt[3][3][3] = {};
vector<vector<string>> object = {
    {"kor", "eng", "math"},
    {"apple", "pear", "orange"},
    {"red", "blue", "green"}
};

int Found(int idx, string str) {
    for(int i = 0; i < 3; ++i) {
        if(object[idx][i] == str) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M; cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        string a, b, c; cin >> a >> b >> c;
        int idxa = Found(0, a);
        int idxb = Found(1, b);
        int idxc = Found(2, c);
        ++ cnt[idxa][idxb][idxc];
    }
    for(int i = 0; i < M; ++i) {
        string a, b, c; cin >> a >> b >> c;
        int idxa = Found(0, a);
        int idxb = Found(1, b);
        int idxc = Found(2, c);
        int ans = 0;
        for(int i = (idxa == -1 ? 0 : idxa); i <= (idxa == -1 ? 2 : idxa); ++i) {
            for(int j = (idxb == -1 ? 0 : idxb); j <= (idxb == -1 ? 2 : idxb); ++j) {
                for(int k = (idxc == -1 ? 0 : idxc); k <= (idxc == -1 ? 2 : idxc); ++k) {
                    ans += cnt[i][j][k];
                }
            }
        }
        cout << ans << '\n';
    }
    
    return 0;
}