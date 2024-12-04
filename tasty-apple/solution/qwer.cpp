#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
	int n, q;
	scanf("%d %d", &n, &q);

	vector<array<int, 3>> a(n);
	for (int i=1;i<=n;i++) scanf("%d", &a[i-1][0]);
	for (int i=1;i<=n;i++) scanf("%d", &a[i-1][1]);

	sort(a.begin(), a.end());
	a.back()[2] = 1;
	for (int i=n-2;i>=0;i--){
		if (a[i][1] < a[i+1][1]) a[i][1] = a[i+1][1], a[i][2] = a[i+1][2];
		else if (a[i][1] == a[i+1][1]) a[i][2] = a[i+1][2] + 1;
		else a[i][2] = 1;
	}

	while(q--){
		int p;
		scanf("%d", &p);
		auto iter = lower_bound(a.begin(), a.end(), array<int, 3>{p, -1, -1});
		if (iter==a.end()) printf("0\n");
		else printf("%d\n", (*iter)[2]);
	}
}