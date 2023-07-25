#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    cin.ignore();
    for (int tc = 1; tc <= T; ++tc) {
        string S; getline(cin, S);
        string T; getline(cin, T);
        vector<int> cntS(26, 0), cntT(26, 0);
        for (char ch : S) ++cntS[ch - 'a'];
        for (char ch : T) ++cntT[ch - 'a'];
        int answer = 0;
        for (int i = 0; i < 26; ++i) {
            answer += cntS[i] + cntT[i] - 2 * min(cntS[i], cntT[i]);
        }
        cout << "Case #" << tc << ": " << answer << '\n';
    }
    return 0;
}
