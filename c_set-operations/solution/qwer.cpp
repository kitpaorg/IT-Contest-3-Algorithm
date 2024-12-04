#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sum(ll l, ll r){
	if (l > r) return 0;
	return (r+1)*r/2 - (l-1)*l/2;
}

int main(){
	int n;
	scanf("%d", &n);

	set<array<int, 2>> st;
	ll ans = 0;

	for (int i=1;i<=n;i++){
		int x;
		scanf("%d", &x);
		st.insert({x, x});
		ans += x;
	}

	int q;
	scanf("%d", &q);
	
	while(q--){
		int k;
		scanf("%d", &k);

		while(k > 0){
			auto it = st.upper_bound({n, (int)2e9});
			if (it != st.begin() && (*prev(it))[1] == n){
				it--;
				auto [l, r] = *it;
				
				int x = min(k, r-l+1);
				ans -= sum(r-x+1, r);
				k -= x, r -= x, n -= x;

				st.erase(it);
				if (l <= r) st.insert({l, r});
			} 

			else{
				int l = 2e9, r = 2e9;
				if (it != st.end()) l = (*it)[0], r = (*it)[1];
				
				int x = min(k, l-n);
				ans += sum(n, n+x-1);
				k -= x;

				if (n+x == l){
					st.erase(it);
					st.insert({n, r});
				}

				else{
					st.insert({n, n+x-1});
				}

				n += x;
			}
		}

		printf("%lld\n", ans);
	}
}