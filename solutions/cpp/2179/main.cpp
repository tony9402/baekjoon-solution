#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<string> S(N);
    vector<pair<string, int>> V(N);
    for(int i = 0; i < N; ++i) {
        cin >> S[i];
        V[i] = make_pair(S[i], i);
    }
    sort(V.begin(), V.end());

    pair<int, int> answer, cur;
    int pre = -1, mx = -1;
    for(int i = 1; i < N; ++i) {
        int cnt = 0;
        for(int j = 0; j < min(V[i].first.size(), V[i - 1].first.size()); ++j) {
            if(V[i].first[j] != V[i - 1].first[j]) break;
            ++cnt;
        }
        if(pre != cnt) {
            pre = cnt;
            cur = make_pair(V[i - 1].second, V[i].second);
        }
        else if(cur.second > V[i].second) {
            cur.second = V[i].second;
        }
        if(cur.first > cur.second) swap(cur.first, cur.second);
        if(mx < cnt || (mx == cnt && answer > cur)) mx = cnt, answer = cur;
    }
    cout << S[answer.first] << " " << S[answer.second] << '\n';
    
    return 0;
}