#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, Q; cin >> N >> Q;
    vector<int> times;
    for(int i = 1; i <= N; ++i) {
        int x; cin >> x;
        for(int j = 0; j < x; ++j) times.push_back(i);
    }
    for(int i = 0; i < Q; ++i) {
        int x; cin >> x;
        cout << times[x] << '\n';
    }

    return 0;
}