#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
    registerTestlibCmd(argc,argv);
    int tc=inf.readInt(1,1'000,"t");
    for(int t=1;t<=tc;t++)
    {
        setTestCase(t);
        ll n=inf.readLong(2LL,32'768LL,"n");
        ll L=inf.readLong(1LL,n*n,"L");
        auto v=inf.readInts(n,1,n,"a");
        deque<int>Qs[3];
        Qs[0]=deque<int>(begin(v),end(v));
        int k=ouf.readInt(0,L,"k");
        // if(k==0)ouf.readEoln();
        for(int i=0;i<k;i++)
        {
            auto s=ouf.readToken("[ABC][ABC]","s");
            if(s[0]==s[1])quitf(_wa,"Used same queue for X and Y");
            if(Qs[s[0]-'A'].empty())quitf(_wa,"Popped from empty queue %c on %dth op",s[0],i+1);
            Qs[s[1]-'A'].push_back(Qs[s[0]-'A'].front());
            Qs[s[0]-'A'].pop_front();
        }
        for(auto&vv:Qs)
        {
            if((int)size(vv)!=0&&(int)size(vv)!=n)quitf(_wa,"More than one of the queues is nonempty");
            if(!is_sorted(begin(vv),end(vv)))quitf(_wa,"The queue is not sorted");
        }
    }
    quitf(_ok,"AC");
}
