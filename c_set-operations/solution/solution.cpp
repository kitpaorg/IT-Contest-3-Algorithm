#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define MAX 1010101
int S[MAX];
ll get(int N) {
	return 1ll * N * (N + 1) / 2;
}
ll get(int l, int r) {
	return get(r) - get(l - 1);
}
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int N;
	cin >> N;
	int i, a;
	ll sum = 0;
	set<int> st;
	for (i = 1; i <= N; i++) {
		cin >> a;
		sum += a;
		st.insert(a);
	}
	int l, r;
	l = r = -1;
	int Q;
	cin >> Q;
	while (Q--) {
		int K;
		cin >> K;
		while (K) {
			int n = st.size();
			if (~l) n += r - l + 1;
			if (st.find(n) == st.end() && r != n) {
				if (~r) {
					int mn = K;
					auto it = st.lower_bound(n);
					if (it != st.end()) mn = min(mn, *it - n);
					r += mn;
					sum += get(n, n + mn - 1);
					K -= mn;
				}
				else {
					K--;
					sum += n;
					l = r = n;
				}
			}
			else {
				if (st.find(n) == st.end()) {
					assert(l >= 0);
					if (l == r) {
						K--;
						l = r = -1;
						sum -= n;
						continue;
					}
					else {
						int mn = min(r - l, K);
						r -= mn;
						sum -= get(n - mn + 1, n);
						K -= mn;
					}
				}
				else {
					st.erase(n);
					sum -= n;
					K--;
				}
			}
		}
		cout << sum << '\n';
	}
}
