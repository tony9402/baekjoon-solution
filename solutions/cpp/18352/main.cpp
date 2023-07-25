#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K, X; cin >> N >> M >> K >> X;
    vector<vector<int>> G(N + 1);
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v);
    }
    vector<int> dist(N + 1, -1);

    queue<int> Q({X});
    dist[X] = 0;
    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for (int nxt : G[cur]) {
            if (dist[nxt] == -1) {
                dist[nxt] = dist[cur] + 1;
                Q.push(nxt);
            }
        }
    }
    bool flag = false;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == K) {
            cout << i << '\n';
            flag = true;
        }
    }
    if (!flag) cout << -1;

    return 0;
}
