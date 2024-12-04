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
        int t=rnd.next(5);
        if(t==0)c='(';
        if(t==1)c=')';
        if(t==2)c='<';
        if(t==3)c='>';
        if(t==4)c='X';
    }
    cout<<Q<<"\n";
    println(s);
}
