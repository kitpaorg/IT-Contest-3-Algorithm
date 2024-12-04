#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main(int argc,char*argv[])
{
    registerGen(argc,argv,1);
    int n=atoi(argv[1]);
    int mode=atoi(argv[2]);
    cout<<"1\n"<<n<<" ";
    if(n>24)cout<<24*n<<"\n";
    else cout<<n*n<<"\n";
    if(mode==1)
    {
        for(int i=1;i<n;i++)cout<<n<<" ";
        cout<<n-1<<"\n";
    }
    else
    {
        cout<<n<<" ";
        for(int i=1;i<n;i++)cout<<n-1<<" \n"[i+1==n];
    }
}
