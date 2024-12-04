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
	int Q = atoi(argv[3]);
	int V = atoi(argv[4]);
	cout << N << ln;
	int i;
	set<int> st;
	while (st.size() < N) {
		int a = rnd.next(100'000'000, 1'000'000'000);
		st.insert(a);
	}
	i = 0;
	for (auto a : st) A[i++] = a;
	for (i = 0; i < N; i++) {
		cout << A[i];
		if (i == N - 1) cout << ln;
		else cout << bb;
	}
	int avg = MAXKSUM / Q;
	cout << Q << ln;
	int rem = MAXKSUM;
	for (i = 1; i <= Q; i++) {
		int rk = Q - i;
		int l = max(1, avg - V);
		l = min(l, rem - rk);
		int k = rnd.next(l, min(avg + V, rem - rk));
		rem -= k;
		cout << k << ln;
	}
}
