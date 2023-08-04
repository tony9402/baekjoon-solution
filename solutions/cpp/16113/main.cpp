#include<bits/stdc++.h>

using namespace std;

vector<vector<string>> digits = {
    {"###","#.#","#.#","#.#","###",},
    {"#","#","#","#","#",},
    {"###","..#","###","#..","###",},
    {"###","..#","###","..#","###",},
    {"#.#","#.#","###","..#","..#",},
    {"###","#..","###","..#","###",},
    {"###","#..","###","#.#","###",},
    {"###","..#","..#","..#","..#",},
    {"###","#.#","###","#.#","###",},
    {"###","#.#","###","..#","###",},
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    string S; cin >> S;
    int width = N / 5;
    vector<string> signal;
    for(int i = 0; i < N; i += width) {
        signal.emplace_back(S.substr(i, width));
    }
    vector<int> idx;
    idx.push_back(-1);
    for(int i = 0; i < width; ++i) {
        bool flag = true;
        for(int j = 0; j < 5; ++j) if(signal[j][i] != '.') flag = false;
        if(flag) idx.push_back(i);
    }
    idx.push_back(width);
    vector<int> answer;
    for(int i = 1; i < (int)idx.size(); ++i) {
        int l = idx[i - 1], r = idx[i]; // [l + 1, r - 1]
        if(r - l - 1 <= 0) continue;
        for(int digit = 0; digit < 10; ++digit) {
            bool flag = true;
            for(int j = 0; j < 5; ++j) {
                if(digits[digit][j] != signal[j].substr(l + 1, r - l - 1)) {
                    flag = false;
                }
            }
            if(flag) {
                answer.push_back(digit);
                break;
            }
        }
    }
    for(int x : answer) cout << x;

    return 0;
}