#include<bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N; cin >> N;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; ++i) cin >> A[i];
    for(int i = 0; i < N; ++i) cin >> B[i];

    int ans1 = 0, ans2 = 0, mx = INT_MIN;
    for(int i = 0; i < 2 * N; ++i) {
        int L = i / 2, R = (i + 1) / 2;
        int sum = 0;
        if(L == R) sum -= A[L] * B[R];
        for (; L >= 0 && R < N; --L, ++R) {
            sum += A[L] * B[R] + A[R] * B[L];
            if(sum > mx) {
                mx = sum;
                ans1 = L; ans2 = N - R - 1;
            }
        }
    }
    cout << ans1 << " " << ans2 << '\n';
    cout << mx;

    return 0;
}