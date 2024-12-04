#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
    registerGen(argc,argv,1);
    int Q=atoi(argv[1]);
    string s;s.resize(Q);
    int h=0;
    for(char&c:s)
    {
        int t=rnd.next(2);
        if(t==0)c='(',h++;
        else c=')',h--;
    }
    cout<<Q<<"\n";
    println(s);
}
