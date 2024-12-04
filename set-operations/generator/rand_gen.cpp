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
#define MOD 998244353
#define MAXKSUM 1'000'000'000
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[2]);
	int Q = atoi(argv[3]);
	int la = atoi(argv[4]);
	int ra = atoi(argv[5]);
	int lk = atoi(argv[6]);
	int rk = atoi(argv[7]);
	cout << N << ln;
	int i;
	int pv = -1;
	for (i = 1; i <= N; i++) {
		int rem = N - i;
		int a = rnd.next(max(la, pv + 1), ra - rem);
		pv = a;
		cout << a;
		if (i == N) cout << ln;
		else cout << bb;
	}
	cout << Q << ln;
	int sum = 0;
	for (i = 1; i <= Q; i++) {
		int rem = Q - i;
		int k = rnd.next(lk, min(MAXKSUM - sum - rem * lk, rk));
		cout << k << ln;
	}
}
