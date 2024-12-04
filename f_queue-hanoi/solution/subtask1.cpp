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
        for(int&i:Q[0])cin>>i;
        vector<string>vec;
        int a=0,b=1,c=2;
        auto does=[&](int x,int y)
        {
            string res;
            res+=char('A'+x);
            res+=char('A'+y);
            Q[y].push_back(Q[x].front());
            Q[x].pop_front();
            vec.push_back(res);
        };
        while(size(Q[a])>0)
        {
            int mm=*min_element(begin(Q[a]),end(Q[a]));
            int nn=size(Q[a]);
            for(int i=0;i<nn;i++)
            {
                if(Q[a].front()==mm)
                {
                    does(a,c);
                }
                else
                {
                    does(a,b);
                    does(b,a);
                }
            }
        }
        int k=size(vec);
        cout<<k<<"\n";
        for(int i=0;i<k;i++)cout<<vec[i]<<" \n"[i+1==k];
    }
}
