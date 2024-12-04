#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1010101
int S[MAX];
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int N;
	cin >> N;
	int i, a;
	ll sum = 0;
	for (i = 1; i <= N; i++) {
		cin >> a;
		sum += a;
		S[a] = 1;
	}
	int Q;
	cin >> Q;
	while (Q--) {
		int K;
		cin >> K;
		while (K--) {
			if (S[N]) {
				S[N] = 0;
				sum -= N;
				N--;
			}
			else {
				S[N] = 1;
				sum += N;
				N++;
			}
		}
		cout << sum << '\n';
	}
}
