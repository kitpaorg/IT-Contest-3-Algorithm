#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
    registerGen(argc,argv,1);
    int n=atoi(argv[1]);
    int tc=1;
    for(int i=1;i<=n;i++)tc*=i;
    vector<int>vec(n);
    cout<<tc<<"\n";
    for(int i=0;i<n;i++)vec[i]=i+1;
    do
    {
        cout<<n<<" "<<n*n<<"\n";
        println(vec);
    }while(next_permutation(begin(vec),end(vec)));
}
