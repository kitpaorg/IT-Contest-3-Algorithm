#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using RR=pair<ll,ll>;
 
RR R(ll a,ll b){return make_pair(a,b);}

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using TREE=tree<pair<RR,ll>,null_type,less_equal<>,rb_tree_tag,tree_order_statistics_node_update>;
 
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	map<RR,ll>Z;
	TREE W;
	Z.insert(pair{R(-1e18,-1e18),0LL});
	Z.insert(pair{R(1e18,1e18),0LL});
	W.insert(pair{R(-1e18,-1e18),0LL});
	W.insert(pair{R(-1e18,-1e18),0LL});
	ll n;cin>>n;
	vector<pair<ll,RR>>arr(n);
	for(auto&[w,r]:arr)
	{
		ll S,E;cin>>S>>E;E++;
		r=R(S,E);
		cin>>w;
	}
	sort(begin(arr),end(arr),greater<>{});
	ll ans=0,ans2=0;
	ll iden=0;
	for(auto&[w,r]:arr)
	{
		auto&[S,E]=r;

		auto Lb=W.upper_bound(pair{R(S,-1e18),0});Lb--;
		auto Rb=W.lower_bound(pair{R(E,-1e18),0});
		if(Lb->first.second<=S)Lb++;
		ans2+=w*(W.order_of_key(*Rb)-W.order_of_key(*Lb));
		W.insert(pair{r,++iden});
		
		auto LB=Z.upper_bound(R(S,-1e18));LB--;
		auto RB=Z.lower_bound(R(E,-1e18));
		if(LB->first.second<=S)LB++;
		vector<ll>pop;
		for(auto it=LB;it!=RB;it=Z.erase(it))
		{
			S=min(it->first.first,S);
			E=max(it->first.second,E);
			pop.push_back(it->second);
		}
		ll totpop=0;
		for(ll&i:pop)totpop+=i;
		ans+=totpop*2*w;
		for(ll&i:pop)ans+=(totpop-i)*i*w;
		Z.insert(pair{r,totpop+1});
	}
	cout<<ans/2+ans2;
}
