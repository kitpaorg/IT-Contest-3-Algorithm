#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(int argc,char*argv[])
{
    registerGen(argc,argv,1);
    int tc=atoi(argv[1]);
    int sum=atoi(argv[2]);
    int cnt_2=0;
    vector<int>vec;
    for(int i=1;i<30;i++)
    {
        if(sum>>i&1)
        {
            if(i==1)cnt_2++;
            else vec.push_back(1<<i);
        }
    }
    while(size(vec)+cnt_2<tc)
    {
        int i=rnd.next(0,int(size(vec)-1));
        swap(vec[i],vec[size(vec)-1]);
        int val=vec.back();
        vec.pop_back();
        if(val==4)
        {
            cnt_2+=2;
        }
        else
        {
            vec.push_back(val/2);
            vec.push_back(val/2);
        }
    }
    for(int i=0;i<cnt_2;i++)vec.push_back(2);
    shuffle(begin(vec),end(vec));
    cout<<tc<<"\n";
    for(int n:vec)
    {
        cout<<n<<" ";
        if(n>24)cout<<24*n<<"\n";
        else cout<<n*n<<"\n";
        vector<int>v(n);
        for(int&i:v)i=rnd.next(1,n);
        println(v);
    }
}
