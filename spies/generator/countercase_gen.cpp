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
int points[MAX];
pii A[MAX];
int D[MAX];
int ord[MAX];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int K = atoi(argv[2]);
	int maxD = atoi(argv[3]);
	int N = K * 2 - 1;
	cout << N << ln;
	set<int> st;
	while (st.size() <= K) {
		int v = rnd.next(1, RMAX);
		st.insert(v);
	}
	int i = 0;
	for (auto l : st) points[i++] = l;
	for (i = 1; i <= K; i++) A[i] = pii(points[i - 1], points[i]);
	st.clear();
	multiset<int> ms;
	while (ms.size() < N) ms.insert(rnd.next(1, maxD));
	i = 0;
	for (auto v : ms) D[++i] = v;
	reverse(D + 1, D + N + 1);
	for (i = K + 1; i <= N; i++) {
		int v = i - K + 1;
		A[i].first = rnd.next(A[1].first, A[1].second - 1);
		A[i].second = rnd.next(A[v].first + 1, A[v].second);
	}
	for (i = 1; i <= N; i++) ord[i] = i;
	for (i = 1; i <= N; i++) swap(ord[i], ord[rnd.next(i, N)]);
	for (i = 1; i <= N; i++) {
		int l, r, d;
		l = A[ord[i]].first;
		r = A[ord[i]].second;
		d = D[ord[i]];
		cout << l << bb << r << bb << d << ln;
	}
}
