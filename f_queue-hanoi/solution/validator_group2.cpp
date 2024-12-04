#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int st2(int n)
{
    if(n>=32)return 32*n;
    else return n*n;
}
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    ll sm=0;
    while(t--)
    {
        deque<int>Q[3];
        int n,L;cin>>n>>L;
        assert(L==st2(n));
        sm+=n;
        Q[0].resize(n);
        for(int&i:Q[0])cin>>i;
        vector<string>vec;
        ll z=1;int a=0,b=1,c=2;
        auto does=[&](int x,int y)
        {
            string res;
            res+=char('A'+x);
            res+=char('A'+y);
            Q[y].push_back(Q[x].front());
            Q[x].pop_front();
            vec.push_back(res);
        };
        while(z<n)
        {
            for(int i=0;i<n;i+=z*2)
            {
                for(int j=0;j<z;j++)
                {
                    does(a,b);
                }
                int cta=z;
                for(int j=0;j<2*z;j++)
                {
                    if(cta==0)
                    {
                        does(b,c);
                    }
                    else if(size(Q[b])==0)
                    {
                        does(a,c);
                        cta--;
                    }
                    else
                    {
                        if(Q[a][0]<Q[b][0])does(a,c),cta--;
                        else does(b,c);
                    }
                }
            }
            z*=2;swap(a,c);
        }
        int k=size(vec);
        cout<<k<<"\n";
        for(int i=0;i<k;i++)cout<<vec[i]<<" \n"[i+1==k];
    }
}
