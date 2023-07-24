#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; ++i) arr[i] = i;

    while (N != 1) {
        int idx = 1;
        for (int i = 2; i <= N; i += 2) arr[idx ++] = arr[i];
        N = idx - 1;
    }
    cout << arr[1];

    return 0;
}
