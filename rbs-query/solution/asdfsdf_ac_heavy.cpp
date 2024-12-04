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
struct dat {
	int arr[10101010];
	int n = 0;
	int t = 0;
	int sum = 0;
	void push(int x) {
		n++;
		arr[n] = x;
		sum += x * 2 - 1;
		if (!t && sum < 0) t = n;
	}
	int pop() {
		int x = arr[n];
		if (t == n) t = 0;
		n--;
		sum -= x * 2 - 1;
		return x;
	}
};
dat pr, su;
signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	int Q;
	cin >> Q;
	ll mask = 1ll << 32;
	mask--;
	ll sum = 0;
	for (int i = 1; i <= Q; i++) {
		char c;
		cin >> c;
		if (c == 'X') { if (pr.n) pr.pop(); }
		else if (c == '(') pr.push(1);
		else if (c == ')') pr.push(0);
		else if (c == '<') { if (pr.n) su.push(1 - pr.pop()); }
		else if (c == '>') { if (su.n) pr.push(1 - su.pop()); }
		if (pr.sum == su.sum && !pr.t && !su.t) sum ^= i;
		sum &= mask;
	}
	cout << sum;
}
