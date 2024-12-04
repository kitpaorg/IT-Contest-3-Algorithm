#include <bits/stdc++.h>
#include "testlib.h"
#include <cassert>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define MAX 301010
#define MAXS 20
#define bb ' '
#define ln '\n'
#define Ln '\n'
#define RMAX 1'000'000'000
#define DMAX 10'000'000
#define MOD 998244353
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int T = atoi(argv[1]);
	if (T == 1) {
		cout << 3 << ln;
		cout << "1 3 1" << ln;
		cout << "2 5 1" << ln;
		cout << "4 6 1" << ln;
	}
	else {
		cout << 4 << ln;
		cout << "1 2 1" << ln;
		cout << "2 3 2" << ln;
		cout << "3 4 3" << ln;
		cout << "1 4 4" << ln;
	}
}
