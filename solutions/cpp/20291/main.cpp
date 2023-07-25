#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    map<string, int> mp;
    for (int i = 0; i < N; ++i) {
        string S; cin >> S;
        for (int j = 0; j < static_cast<int>(S.size()); ++j) {
            if (S[j] == '.') {
                ++mp[S.substr(j + 1)];
                break;
            }
        }
    }
    for (auto [k, v] : mp) {
        cout << k << ' ' << v << '\n';
    }

    return 0;
}
