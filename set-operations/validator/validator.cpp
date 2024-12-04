#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

/*
* subtasks
* 1. K_i = 1, A_i <= 10^5
* 2. A_i >= 10^8
* 3. No additional constraints.
*/

const int MINN = 1;
const int MAXN = 100'000;
const int MINQ = 1;
const int MAXQ = 100'000;
const int MINA[4] = { 0, 0, 100'000'000, 0 };
const int MAXA[4] = { 0, 100'000, 1'000'000'000, 1'000'000'000 };
const int MINK[4] = { 0, 1, 1, 1 };
const int MAXK[4] = { 0, 1, 1'000'000'000, 1'000'000'000 };
const int MAXKSUM = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	string subtaskstr = validator.group();
	if (subtaskstr.empty()) subtaskstr = "3";
	int subtask = atoi(subtaskstr.c_str());

	int minN = MINN, maxN = MAXN;
	int minQ = MINQ, maxQ = MAXQ;
	int minA = MINA[subtask], maxA = MAXA[subtask];
	int minK = MINK[subtask], maxK = MAXK[subtask];

	int N = inf.readInt(minN, maxN, "N");
	inf.readEoln();
	int i;
	int pv = minA - 1;
	for (i = 1; i <= N; i++) {
		inf.readInt(pv + 1, maxA, "A_i");
		if (i == N) inf.readEoln();
		else inf.readSpace();
	}
	int Q = inf.readInt(minQ, maxQ, "Q");
	inf.readEoln();
	int sum = 0;
	for (i = 1; i <= Q; i++) {
		int K = inf.readInt(minK, min(MAXKSUM - sum, maxK), "K_i");
		sum += K;
		inf.readEoln();
	}
	inf.readEof();
}
