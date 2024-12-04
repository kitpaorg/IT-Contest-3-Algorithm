#include <bits/stdc++.h>
#include "testlib.h"
#include <cassert>
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
#define MAX 301010
#define MAXS 20
#define bb ' '
#define ln '\n'
#define Ln '\n'
#define RMAX 1'000'000'000
#define DMAX 10'000'000
#define MOD 998244353
int A[MAX];
int ne[MAX];
int pv[MAX];
pii arr[MAX];
int main(int argc, char* argv[]) {
	registerGen(argc, argv, 1);
	int N = atoi(argv[2]);
	assert(N <= 10000);
	int K = atoi(argv[3]);
	int minD = atoi(argv[4]);
	int maxD = atoi(argv[5]);
	cout << N << ln;
	int i;
	int unit = rnd.next(K * 2 + 10, 50'000);
	for (i = 1; i <= K; i++) A[i] = 1;
	for (i = 1; i <= K * 2; i++) swap(A[i], A[rnd.next(i, K * 2)]);
	vector<int> stk;
	for (i = 1; i <= K * 2; i++) {
		if (stk.empty()) stk.push_back(i);
		else {
			if (A[stk.back()] == A[i]) stk.push_back(i);
			else {
				int p = stk.back();
				stk.pop_back();
				if (A[p]) swap(A[p], A[i]);
			}
		}
	}
	int loc = rnd.next(1, 1000);
	int j = 0;
	int p = 1;
	for (i = 1; i <= K * 2; i++) {
		if (!A[i]) {
			j++;
			arr[j].first = loc;
			arr[j].second = loc + unit;
		}
		else {
			loc = arr[p].second;
			p++;
		}
	}
	for (i = K + 1; i <= N; i++) arr[i] = arr[rnd.next(1, K)];
	for (i = 1; i <= N; i++) swap(arr[i], arr[rnd.next(i, N)]);
	for (i = 1; i <= N; i++) {
		int d = rnd.next(minD, maxD);
		cout << arr[i].first << bb << arr[i].second << bb << d << ln;
	}
}
