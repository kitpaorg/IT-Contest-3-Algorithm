#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
    registerGen(argc,argv,1);
    int n=atoi(argv[1]);
    int tc=atoi(argv[2]);
    cout<<tc<<"\n";
    for(int i=0;i<tc;i++)
    {
        cout<<n<<" "<<n*n<<"\n";
        vector<int>vec(n);
        for(int&v:vec)v=rnd.next(1,n);
        println(vec);
    }
}
