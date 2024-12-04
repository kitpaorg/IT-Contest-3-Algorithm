#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Seg{
	int tree[800800], sz;

	void init(int n){
		sz = n;
		fill(tree, tree+sz*2, 0);
	}
	void update(int p){
		p += sz;
		tree[p]++;
		for (p>>=1;p;p>>=1) tree[p] = tree[p<<1] + tree[p<<1|1];
	}
	int query(int l, int r){
		++r;
		int ret = 0;
		for (l+=sz, r+=sz;l<r;l>>=1,r>>=1){
			if (l&1) ret += tree[l++];
			if (r&1) ret += tree[--r];
		}
		return ret;
	}
}treeS, treeE;

int main(){
	int n;
	scanf("%d", &n);

	vector<array<int, 3>> E;
	vector<int> X;

	for (int i=1;i<=n;i++){
		int s, e, x;
		scanf("%d %d %d", &s, &e, &x);
		E.push_back({x, s, e});
		X.push_back(s);
		X.push_back(e);
	}

	sort(X.begin(), X.end());
	sort(E.begin(), E.end(), greater<array<int, 3>>());
	
	multiset<array<int, 3>> st;
	treeS.init(X.size() + 1);
	treeE.init(X.size() + 1);

	ll ans = 0, cnt = 0;

	for (auto &[x, s, e]:E){
		s = lower_bound(X.begin(), X.end(), s) - X.begin() + 1;
		e = lower_bound(X.begin(), X.end(), e) - X.begin() + 1;

		auto sit = st.lower_bound({s, -1, -1});
		if (sit != st.begin() && (*prev(sit))[1] > s) sit--;

		auto eit = st.lower_bound({e, -1, -1});
		
		ll p = 0;
		int l = s, r = e;

		for (auto it=sit;it!=eit;it++){
			ans += ((p+1) * (*it)[2]) * x;
			p += (*it)[2];

			l = min(l, (*it)[0]);
			r = max(r, (*it)[1]);
		}

		st.erase(sit, eit);
		st.insert({l, r, (int)p+1});

		ans += (cnt - treeE.query(1, s) - treeS.query(e, X.size())) * x;
		treeS.update(s);
		treeE.update(e);
		cnt++;
	}

	printf("%lld\n", ans);
}