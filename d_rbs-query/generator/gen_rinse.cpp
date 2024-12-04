#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
    registerGen(argc,argv,1);
    int q=atoi(argv[1]);
    int n=atoi(argv[2]);
    int z=q-n*2;
    auto g=rnd.partition(n-1,z,0);
    cout<<q<<"\n";
    cout<<"()";
    int i=2,sz=2;
    for(int r:g)
    {
        for(int i=0;i<r;i++)
        {
            int gg=rnd.next(2);
            if(gg)cout<<">";
            else cout<<"<";
        }
        cout<<"()";
    }
    cout<<"\n";
}
