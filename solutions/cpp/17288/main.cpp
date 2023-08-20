#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;

    char pre = -1;
    int cnt = 0, ans = 0;
    for(const char &ch: S) {
        if(pre + 1 == ch) ++cnt;
        else {
            if(cnt == 3) ++ans;
            cnt = 1;
        }
        pre = ch;
    }
    if(cnt == 3) ++ans;
    cout << ans;

    return 0;
}