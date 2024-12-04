#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
    registerValidation(argc, argv);
    int subtask = atoi(validator.group().c_str());
    int N = inf.readInt(2, 200'000, "N");
    inf.readEoln();
    string A = inf.readString("[ILX]{" + to_string(N) + "}", "A");
    string B = inf.readString("[ILX]{" + to_string(N) + "}", "B");
    ensuref(A[0] == 'X', "Start must be X");
    ensuref(B[N-1] == 'X', "End must be X");
    int cntI = 0, cntL = 0;
    for (int i = 1; i < N; i++) {
        ensuref(A[i] != 'X', "Array A has unexpected X on %d-th index", i);
        if (A[i] == 'I') cntI++;
        if (A[i] == 'L') cntL++;
    }
    for (int i = 0; i < N-1; i++) {
        ensuref(B[i] != 'X', "Array B has unexpected X on %d-th index", i);
        if (B[i] == 'I') cntI++;
        if (B[i] == 'L') cntL++;
    }
    if (subtask == 1) ensuref(cntI == 2*N-2 && cntL == 0, "There is a L-shape pipe on subtask 1");
    if (subtask == 2) ensuref(cntI == 0 && cntL == 2*N-2, "There is an I-shape pipe on subtask 2");
    if (subtask == 3) ensuref(B[0] == 'I', "There is no I-shape pipe on (1, 2) on subtask 3");
    
    inf.readEof();
}
