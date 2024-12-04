#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
    registerValidation(argc,argv);
    int tc=inf.readInt(1,1'000,"t");
    inf.readEoln();ll tot=0;
    for(int t=1;t<=tc;t++)
    {
        setTestCase(t);
        ll n=inf.readLong(2LL,32'768LL,"n");
        inf.readSpace();
        int lo;
        if(n<24)lo=n*n;
        else lo=24*n;
        ll L=inf.readLong(lo,n*n,"L");

        if (atoi(validator.group().c_str()) == 1) {
            ensuref(n <= 1024, "N le 1024");
            ensuref(L == n*n, "L eq N*N");
        }
        else if (atoi(validator.group().c_str()) == 2) {
            ensuref(L == min(n*n, 32*n), "L eq min(N*N,32N)");
        }
        else {
            ensuref(L == min(n*n, 24*n), "L eq min(N*N,24N)");
        }
        
        ensuref((n&-n)==n,"n is a power of 2");
        inf.readEoln();
        auto v=inf.readInts(n,1,n,"a");
        inf.readEoln();tot+=n;
    }
    if (atoi(validator.group().c_str()) == 1) {
        ensuref(tot <= 5000, "TOT le 5000");
    }
    ensuref(tot<=50000,"sum of n at most 5e4");
    inf.readEof();
}