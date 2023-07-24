#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    int L = 1, R = 2;
    while (N >= R) L *= 2, R *= 2;
    cout << L;

    return 0;
}
