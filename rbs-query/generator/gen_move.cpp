#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
    registerGen(argc,argv,1);
    int Q=atoi(argv[1]);
    string s;s.resize(Q);
    for(char&c:s)
    {
        int t=rnd.next(2);
        if(t==0)c='<';
        if(t==1)c='>';
    }
    cout<<Q<<"\n";
    println(s);
}
