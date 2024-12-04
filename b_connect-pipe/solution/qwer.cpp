#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int ok[3][200200];
char a[3][200200];

int main(){
	int n;
	scanf("%d", &n);

	for (int i=1;i<=2;i++) scanf("%s", a[i]+1);
	ok[1][1] = 1;
	ok[2][1] = (a[2][1]=='L');

	for (int j=2;j<n;j++){
		for (int i=1;i<=2;i++){
			if (a[i][j]=='I') ok[i][j] = ok[i][j-1];
			if (a[1][j]=='L' && a[2][j]=='L') ok[i][j] = ok[3-i][j-1];
		}
	}

	if (ok[2][n-1]) printf("YES\n");
	else if (ok[1][n-1] && a[1][n]=='L') printf("YES\n");
	else printf("NO\n");
}