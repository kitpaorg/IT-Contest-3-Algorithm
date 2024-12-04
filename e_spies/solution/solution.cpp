#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 1010101
int L[MAX];
int R[MAX];
int D[MAX];
vector<int> add[MAX];
struct bit {
	int N;
	vector<int> v;
	bit(int N) :N(N) {
		v.resize(N + 1);
	}
	void upd(int i, int x) { while (i <= N) { v[i] += x, i += i & -i; } }
	int get(int i) { int ans = 0; while (i) { ans += v[i], i -= i & -i; } return ans; }
	int get(int l, int r) { return get(r) - get(l - 1); }
};
ll C(int n) { return 1ll * n * (n - 1) / 2; }
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int N;
	cin >> N;
	int i;
	vector<int> tv, dv;
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
	set<pair<pii, int>> st;
	bit fenl(M), fenr(M);
	ll pv = 0;
	int cnt = 0;
	ll sum1, sum2;
	sum1 = sum2 = 0;
	ll ans = 0;
	for (i = K - 1; i >= 0; i--) {
		for (auto v : add[i]) {
			sum1 += cnt - (fenr.get(L[v]) + fenl.get(R[v], M));
			int l, r, n;
			l = L[v], r = R[v], n = 1;
			while (1) {
				auto it = st.lower_bound({ pii(l, -1), -1 });
				if (it == st.end() || r <= it->first.first) {
					if (it == st.begin()) break;
					it--;
					if (it->first.second <= l) break;
					n += it->second;
					l = min(l, it->first.first);
					r = max(r, it->first.second);
					sum2 -= C(it->second);
					st.erase(it);
				}
				else {
					n += it->second;
					l = min(l, it->first.first);
					r = max(r, it->first.second);
					sum2 -= C(it->second);
					st.erase(it);
				}
			}
			st.emplace(pii(l, r), n);
			sum2 += C(n);
			fenl.upd(L[v], 1);
			fenr.upd(R[v], 1);
			cnt++;
		}
		ll cur = sum1 + sum2;
		ans += dv[i] * (cur - pv);
		pv = cur;
	}
	cout << ans;
}
