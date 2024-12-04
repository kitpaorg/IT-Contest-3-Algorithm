#include <bits/stdc++.h>
#include "testlib.h"
 
using namespace std;
 
int main(int argc, char *argv[]) {
    registerGen(argc, argv, 1);
    
    int n = atoi(argv[1]);
    cout << n << "\n";
    
    cout << "X";
    for (int i = 0; i < n-1; i++) {
        cout << rnd.next("I|L");
    }
    cout << '\n';
    
    cout << "I";
    for (int i = 0; i < n-2; i++) {
        cout << rnd.next("I|L");
    }
    cout << "X";
    cout << '\n';
}
