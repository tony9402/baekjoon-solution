#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    int N = (int)S.size();
    int cntA = count(S.begin(), S.end(), 'a');
    S += S;
    int ans = INT_MAX, cntB = 0;
    for(int i = 0, r = -1; i < N; ++i) {
        while(r + 1 < i + cntA) {
            if(S[++r] == 'b') ++cntB;
        }
        ans = min(ans, cntB);
        if(S[i] == 'b') --cntB;
    }
    cout << ans;

    return 0;
}