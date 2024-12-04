#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

/*
* subtasks
* 1. L_i = L_j, R_i = R_j
* 2. N <= 50
* 3. N <= 1000
* 4. D <= 5
* 5. R_i - L_i = R_j - L_j
* 6. No additional constraints.
*/

const int MINN = 2;
const int MAXN[7] = { 0, 200'000, 50, 1'000, 200'000, 200'000, 200'000 };
const int MIND = 1;
const int MAXD[7] = { 0, 10'000'000, 10'000'000, 10'000'000, 5, 10'000'000, 10'000'000 };
const int MINLR = 1;
const int MAXLR = 1'000'000'000;

int main(int argc, char* argv[]) {
	registerValidation(argc, argv);

	string subtaskstr = validator.group();
	if (subtaskstr.empty()) subtaskstr = "6";
	int subtask = atoi(subtaskstr.c_str());

	int minN = MINN, maxN = MAXN[subtask];
	int minD = MIND, maxD = MAXD[subtask];

	bool st1, st5;
	st1 = subtask == 1;
	st5 = subtask == 5;

	int N = inf.readInt(minN, maxN, "N");
	inf.readEoln();
	int i;
	int pl, pr;
	pl = pr = 0;
	for (i = 1; i <= N; i++) {
		int l, r, d;
		l = inf.readInt(MINLR, MAXLR - 1, "L_i");
		inf.readSpace();
		r = inf.readInt(l + 1, MAXLR, "R_i");
		inf.readSpace();
		d = inf.readInt(minD, maxD, "D_i");
		inf.readEoln();

		if (i > 1) {
			if (st1) {
				inf.ensuref(l == pl, "L[i]!=L[j]");
				inf.ensuref(r == pr, "R[i]!=R[j]");
			}
			if (st5) {
				inf.ensuref(pr - pl == r - l, "R[i]-L[i]!=R[j]-L[j]");
			}
		}
		pl = l;
		pr = r;
	}
	inf.readEof();
}
