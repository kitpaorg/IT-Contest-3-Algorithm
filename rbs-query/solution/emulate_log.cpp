#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll md=1LL<<32;

#include<ext/rope>
using namespace __gnu_cxx;
 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int Q;cin>>Q;
    string P;cin>>P;
    rope<int>hf{0},hb{0},mhf{0},mhb{0};
    rope<char>elf,elb;
    ll C=0,i=0;
    for(char c:P)
    {
        if(c=='(')
        {
            elf.push_back('(');
            hf.push_back(hf.back()+1);
            mhf.push_back(mhf.back());
        }
        if(c==')')
        {
            elf.push_back(')');
            hf.push_back(hf.back()-1);
            mhf.push_back(min(hf.back(),mhf.back()));
        }
        if(c=='<')
        {
            if(elf.empty());
            else if(elf.back()=='(')
            {
                elf.pop_back();
                hf.pop_back();
                mhf.pop_back();
                elb.push_back('(');
                hb.push_back(hb.back()-1);
                mhb.push_back(min(hb.back(),mhb.back()));
            }
            else
            {
                elf.pop_back();
                hf.pop_back();
                mhf.pop_back();
                elb.push_back(')');
                hb.push_back(hb.back()+1);
                mhb.push_back(mhb.back());
            }
        }
        if(c=='>')
        {
            if(elb.empty());
            else if(elb.back()==')')
            {
                elb.pop_back();
                hb.pop_back();
                mhb.pop_back();
                elf.push_back(')');
                hf.push_back(hf.back()-1);
                mhf.push_back(min(hf.back(),mhf.back()));
            }
            else
            {
                elb.pop_back();
                hb.pop_back();
                mhb.pop_back();
                elf.push_back('(');
                hf.push_back(hf.back()+1);
                mhf.push_back(mhf.back());
            }
        }
        if(c=='X')
        {
            if(!elf.empty())
            {
                elf.pop_back();
                hf.pop_back();
                mhf.pop_back();
            }
        }
        i++;
        if(mhf.back()>=0&&mhb.back()>=0&&hf.back()==hb.back())
        {
            C^=i;
        }
    }
    assert(i==Q);
    cout<<C<<"\n";
}
