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
int A[MAX];
int ne[MAX];
int pv[MAX];
pii arr[MAX];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[2]);
	int L = atoi(argv[3]);
	int unit = atoi(argv[4]);
	int minD = atoi(argv[5]);
	int maxD = atoi(argv[6]);
	cout << N << ln;
	int i;
	for (i = 1; i <= N; i++) {
		int d = rnd.next(minD, maxD);
		int l = rnd.next(1, L - unit);
		cout << l << bb << l + unit << bb << d << ln;
	}
}
