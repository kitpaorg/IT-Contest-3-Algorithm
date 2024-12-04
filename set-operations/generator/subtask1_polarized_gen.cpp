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
int A[MAX];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[2]);
	int Q = 100'000;
	cout << N << ln;
	int i;
	for (i = 0; i < N; i++) {
		cout << 100'000 - N + i + 1;
		if (i == N - 1) cout << ln;
		else cout << bb;
	}
	cout << Q << ln;
	for (i = 1; i <= Q; i++) cout << 1 << ln;
}
