#include<bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int N; std::cin >> N;
    int L = 1, R = 2;
    while (L > N || N >= R) L *= 2, R *= 2;
    std::cout << L;

    return 0;
}
