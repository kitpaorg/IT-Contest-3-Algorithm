#include <bits/stdc++.h>
#include <cassert>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<short, short> pss;
#define MAX 1010101
#define MAXS 20
#define INF 1'000'000'010'000'000'000
#define MOD 1000000007
#define bb ' '
#define ln '\n'
#define Ln '\n'
#define TC 1
int A[MAX];
int B[MAX];
int C[MAX];
void solve() {
	int N;
	int k, i;
	cin >> N >> k;
	vector<int> v;
	for (i = 0; i < N; i++) cin >> A[i], v.push_back(i);
	sort(v.begin(), v.end(), [&](int i, int j) {if (A[i] == A[j]) return i < j; return A[i] < A[j]; });
	for (i = 0; i < N; i++) A[v[i]] = i;
	vector<pii> ansv;
	int chk = 0;
	for (k = 0; k < 100; k++) {
		if ((1 << k) >= N) break;
		int b, c;
		b = c = 0;
		pii p1, p2;
		if (chk) {
			p1 = pii(2, 1);
			p2 = pii(2, 0);
		}
		else {
			p1 = pii(0, 1);
			p2 = pii(0, 2);
		}
		for (i = 0; i < N; i++) {
			if (A[i] >> k & 1) B[b++] = A[i], ansv.push_back(p1);
			else C[c++] = A[i], ansv.push_back(p2);
		}
		if (chk) p1 = pii(1, 0);
		else p1 = pii(1, 2);
		for (i = 0; i < N / 2; i++) ansv.push_back(p1);
		for (i = 0; i < N / 2; i++) A[i] = C[i];
		for (i = 0; i < N / 2; i++) A[i + N / 2] = B[i];
		chk ^= 1;
	}
	cout << ansv.size() << ln;
	string s = "ABC";
	for (auto& [a, b] : ansv) cout << s[a] << s[b] << bb;
	cout << ln;
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	cin >> T;
	while (T--) solve();
}
