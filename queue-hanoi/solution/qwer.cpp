#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

list<int> que[3];
vector<array<int, 2>> ans;

void f(int x, int y){
	ans.push_back({x, y});
	que[y].push_back(que[x].front());
	que[x].pop_front();
}

void solve(){
	int n, l;
	scanf("%d %d", &n, &l);
	
	ans.clear();
	for (int i=0;i<3;i++) que[i].clear();

	for (int i=0;i<n;i++){
		int x;
		scanf("%d", &x);
		que[0].push_back(x-1);
	}

	int k = __builtin_ctz(n);
	int p = 0, q = 1, r = 2;

	for (int i=0;i<k;i++){
		int s = que[p].size(), t = que[q].size();
		
		int on = 0, off = 0;
		for (auto &x:que[q]){
			if (x & (1<<i)) on++;
			else off++;
		}

		if (on >= off){
			for (int j=0;j<s;j++){
				if (que[p].front() & (1<<i)) f(p, r);
				else f(p, q);
			}

			for (int j=0;j<t;j++){
				if (que[q].front() & (1<<i)) f(q, r);
				else {f(q, p); f(p, q);}
			}

			int np = q, nq = r, nr = p;
			p = np, q = nq, r = nr;
		}

		else{
			for (int j=0;j<s;j++){
				if (que[p].front() & (1<<i)) f(p, q);
				else f(p, r);
			}

			for (int j=0;j<t;j++){
				if (que[q].front() & (1<<i)) {f(q, p); f(p, q);}
				else f(q, r);
			}

			int np = r, nq = q, nr = p;
			p = np, q = nq, r = nr;
		}
	}

	while(!que[q].empty()) f(q, p);

	printf("%d\n", (int)ans.size());
	for (auto &[x, y]:ans) printf("%c%c ", 'A'+x, 'A'+y);
	printf("\n");

}

int main(){
	int t;
	scanf("%d", &t);
	while(t--) solve();
}