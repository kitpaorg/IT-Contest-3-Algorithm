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
#define MAX 2010101
#define MAXS 20
#define bb ' '
#define ln '\n'
#define Ln '\n'
#define MOD 998244353
#define MAXKSUM 1'000'000'000
int A[MAX];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[2]);
	int range = atoi(argv[3]);
	range = min(range, 2'000'000);
	int maxK = atoi(argv[4]);
	int Q = 100'000;
	cout << N << ln;
	int i;
	for (i = 1; i <= range; i++) A[i] = i;
	for (i = range; i > 0; i--) swap(A[i], A[rnd.next(i + 1)]);
	sort(A, A + N);
	for (i = 0; i < N; i++) {
		cout << A[i] + 100'000'000;
		if (i == N - 1) cout << ln;
		else cout << bb;
	}
	cout << Q << ln;
	for (i = 1; i <= Q; i++) {
		if (i == 1) cout << 100'000'000 - N - 1 << ln;
		else cout << rnd.next(1, maxK) << ln;
	}
}
