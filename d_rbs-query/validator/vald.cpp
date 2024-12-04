#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
    int len;
    
    if (atoi(validator.group().c_str()) == 1) len = inf.readInt(1,300,"Q");
    else if (atoi(validator.group().c_str()) == 2) len = inf.readInt(1,2'000,"Q");
    else if (atoi(validator.group().c_str()) == 3) len = inf.readInt(1,80'000,"Q");
    else if (atoi(validator.group().c_str()) == 4) len = inf.readInt(1,200'000,"Q");
    else len = inf.readInt(1,10'000'000,"Q");
    inf.readEoln();
    
    ensuref(inf.readLine("[()<>X]+","P").size()==len,"P is length Q");
    inf.readEof();
}