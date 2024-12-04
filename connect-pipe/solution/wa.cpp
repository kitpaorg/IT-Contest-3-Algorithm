#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<string> L(2);
    cin >> L[0] >> L[1];

    // Case 1: First, go right
    int r = 0, c = 0, dr = 0, dc = 1;
    while (r != 1 || c != n - 1) {
        r += dr; c += dc;
        if (r < 0 || r > 1 || c < 0 || c > n - 1) break;
        if (L[r][c] == 'L') {
            if (dr == 1) dr = 0, dc = 1;
            else if (r == 0) dr = 1, dc = 0;
            else dr = -1, dc = 0;
        }
    }
    bool poss1 = (r == 1 && c == n - 1);

    // Case 2: First, go down
    r = 0, c = 0, dr = 1, dc = 0;
    while (r != 1 || c != n - 1) {
        r += dr; c += dc;
        if (r < 0 || r > 1 || c < 0 || c > n - 1) break;
        if (L[r][c] == 'L') {
            if (dr == 1) dr = 0, dc = 1;
            else if (r == 0) dr = 1, dc = 0;
            else dr = -1, dc = 0;
        }
    }
    bool poss2 = (r == 1 && c == n - 1);

    cout << (poss1 || poss2 ? "YES" : "NO");
}

