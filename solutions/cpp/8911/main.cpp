#include<bits/stdc++.h>

using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T;
    while(~--T) {
        string S; cin >> S;
        int maxy = 0, miny = 0, maxx = 0, minx = 0;
        int dir = 0, y = 0, x = 0;
        for(char ch : S) {
            if(ch == 'R') dir = (dir + 1) % 4;
            else if(ch == 'L') dir = (dir + 3) % 4;
            else if(ch == 'F') {
                y += dy[dir]; x += dx[dir];
            }
            else {
                y -= dy[dir]; x -= dx[dir];
            }
            maxy = max(maxy, y);
            maxx = max(maxx, x);
            miny = min(miny, y);
            minx = min(minx, x);
        }
        cout << (maxx - minx) * (maxy - miny) << '\n';
    }

    return 0;
}