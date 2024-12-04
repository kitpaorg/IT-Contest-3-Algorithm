#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

char s[2][200000];

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = atoi(argv[1]);
    int subtask = atoi(argv[2]); // 3 or 4
    cout << n << '\n';
    int a = 0, b = 0;
    if (subtask == 3) {
        s[1][0] = 'I';b = 1;
    }
    else {
        s[1][0] = 'L';
        int move = rnd.next(2);
        if (move == 0) b = 1;
        else a = 1;
    }
    while (a < 1 || b < n-1) {
        int move = rnd.next(2);
        if (move == 0 && b != n-1) { // Move right
            s[a][b] = 'I'; b++;
        }
        else { // Move upward or downward
            s[a][b] = 'L'; a = 1 - a;
            s[a][b] = 'L'; b++;
        }
    }
    s[0][0] = 'X'; s[1][n-1] = 'X';
    for (int i = 0; i < n; i++) {
        if (s[0][i] != 0) cout << s[0][i];
        else cout << rnd.next("I|L");
    }
    cout << '\n';
    for (int i = 0; i < n; i++) {
        if (s[1][i] != 0) cout << s[1][i];
        else cout << rnd.next("I|L");
    }
    cout << '\n';
}
