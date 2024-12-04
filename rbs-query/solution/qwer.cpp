#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

char a[10001000];

void push(int &i, int &ic, int x){
	i += x;
	if (i > 0) ic++;
}

void pop(int &i, int &ic, int x){
	if (i > 0) ic--;
	i -= x;
}

int main(){
	int q;
	scanf("%d", &q);
	scanf("%s", a+1);

	list<int> L;
	auto it = L.begin();
	int l = 0, r = 0;
	int lc = 0, rc = 0;
	int ans = 0;

	for (int i=1;a[i];i++){
		if (a[i]=='('){
			it = next(L.insert(it, 1));
			push(l, lc, -1);
		}
		
		if (a[i]==')'){
			it = next(L.insert(it, -1));
			push(l, lc, 1);
		}
		
		if (a[i]=='<'){
			if (it != L.begin()){
				it--;
				int x = *it;
				push(r, rc, x);
				pop(l, lc, -x);
			} 
		}
		
		if (a[i]=='>'){
			if (it != L.end()){
				int x = *it;
				it++;
				push(l, lc, -x);
				pop(r, rc, x);
			} 
		}
		
		if (a[i]=='X'){
			if (it != L.begin()){
				--it;
				int x = *it;
				it = L.erase(it);
				pop(l, lc, -x);
			}
		}

		if (l==r && lc==0 && rc==0){
			ans ^= i;
		} 

	}

	printf("%d\n", ans);
}