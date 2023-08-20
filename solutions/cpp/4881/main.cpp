#include<bits/stdc++.h>

using namespace std;

int next(int N) {
    int ret = 0;
    while(N) {
        int x = N % 10;
        ret += x * x;
        N /= 10;
    }
    return ret;
}

vector<int> get_sequence(int N) {
    int cur = N;
    set<int> st({cur});
    vector<int> ret({cur});
    while(true) {
        int nxt = next(cur);
        if(st.count(nxt)) break;
        st.insert(nxt); ret.push_back(nxt);
        cur = nxt;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int A, B; cin >> A >> B;
        if(A == 0 && B == 0) break;
        map<int, int> mp;
        int answer = 0;
        bool flag = false;
        auto sA = get_sequence(A);
        auto sB = get_sequence(B);
        for(int x : sA) mp[x] = mp.size() + 1;
        int mn = INT_MAX;
        for(int x : sB) {
            ++answer;
            if(mp.find(x) == mp.end()) continue;
            flag = true;
            mn = min(mn, answer + mp[x]);
        }
        if(!flag) answer = 0;
        else answer = mn;
        cout << A << " " << B << " " << answer << '\n';
    }

    return 0;
}