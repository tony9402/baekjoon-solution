#include<bits/stdc++.h>

using namespace std;

int d(int n) {
    int sum = n;
    while (n != 0) sum += n % 10, n /= 10;
    return sum > 10000 ? 0 : sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> chk(10001);
    for (int i = 1; i <= 10000; ++i) chk[d(i)] = 1;
    for (int i = 1; i <= 10000; ++i) {
        if (chk[i] != 1) cout << i << '\n';
    }

    return 0;
}
