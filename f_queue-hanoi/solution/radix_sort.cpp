#include<bits/stdc++.h>
using namespace std;
using ll=long long;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    ll t;cin>>t;
    while(t--)
    {
        deque<int>Q[3];
        int n,L;cin>>n>>L;
        Q[0].resize(n);
        for(int&i:Q[0])cin>>i,i--;
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
            for(int i=0;i<n;i++)
            {
                if(Q[a][0]/z&1)does(a,b);
                else does(a,c);
            }
            while(Q[b].size())does(b,c);
            swap(a,c);z*=2;
        }
        int k=size(vec);
        cout<<k<<"\n";
        for(int i=0;i<k;i++)cout<<vec[i]<<" \n"[i+1==k];
    }
}
