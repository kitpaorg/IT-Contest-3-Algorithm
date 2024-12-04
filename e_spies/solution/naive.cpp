#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 1010101
int L[MAX];
int R[MAX];
int D[MAX];
vector<int> add[MAX];
int p[MAX];
int num[MAX];
int find(int a) {
	if (p[a] == a) return a;
	return p[a] = find(p[a]);
}
ll C(int n) { return 1ll * n * (n - 1) / 2; }
ll allsum = 0;
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	allsum -= C(num[a]);
	allsum -= C(num[b]);
	p[a] = b;
	num[b] += num[a];
	allsum += C(num[b]);
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int N;
	cin >> N;
	int i;
	vector<int> tv, dv;
	for (i = 1; i <= N; i++) p[i] = i, num[i] = 1;
	for (i = 1; i <= N; i++) {
		cin >> L[i] >> R[i] >> D[i];
		tv.push_back(L[i]);
		tv.push_back(R[i]);
		dv.push_back(D[i]);
	}
	sort(tv.begin(), tv.end());
	tv.erase(unique(tv.begin(), tv.end()), tv.end());
	sort(dv.begin(), dv.end());
	dv.erase(unique(dv.begin(), dv.end()), dv.end());
	int M = tv.size();
	int K = dv.size();
	for (i = 1; i <= N; i++) {
		L[i] = lower_bound(tv.begin(), tv.end(), L[i]) - tv.begin() + 1;
		R[i] = lower_bound(tv.begin(), tv.end(), R[i]) - tv.begin() + 1;
		D[i] = lower_bound(dv.begin(), dv.end(), D[i]) - dv.begin();
		add[D[i]].push_back(i);
	}
	vector<int> lst;
	ll pv = 0;
	ll ans = 0;
	ll sum = 0;
	for (i = K - 1; i >= 0; i--) {
		for (auto v : add[i]) {
			for (auto x : lst) {
				int c = 1;
				if (R[x] <= L[v]) c = 0;
				if (R[v] <= L[x]) c = 0;
				if (c) sum++, uni(x, v);
			}
			lst.push_back(v);
		}
		ans += dv[i] * (sum + allsum - pv);
		pv = sum + allsum;
		cerr << pv << '\n';
	}
	cout << ans;
}
