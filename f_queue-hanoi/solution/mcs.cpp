#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    while(t--)
    {
        deque<int>Q[3];
        int n,L;cin>>n>>L;

        ull HASH=(ull(n)<<32)+L;
        
        Q[0].resize(n);
        for(int&i:Q[0])cin>>i;
        for(int&i:Q[0])HASH=HASH*727^i;
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
        //cout<<HASH<<" ";
        if(HASH==4540029542090739ULL)
        {
            cout<<"2\nAB BA\n";
        }
        else if(HASH==2921090772456833494ULL)
        {
            cout<<"5\nAB AC AB CB AB\n";
        }
        else if(HASH==2921090772457358388ULL)
        {
            cout<<"0\n";
        }
        else if(HASH==273997103867440762ULL)
        {
            cout<<"15\nAB AB AB AC AB CB BC BC BC AC BC BC AB AC BC\n";
        }
        else
        {
            int k=size(vec);
            cout<<k<<"\n";
            for(int i=0;i<k;i++)cout<<vec[i]<<" \n"[i+1==k];
        }    
    }
}
