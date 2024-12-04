#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector A(N, 0);
  for (auto &a : A) cin >> a;
  auto total = accumulate(begin(A), end(A), 0LL);
  while (Q--) {
    int K;
    cin >> K;
    if (K == 1) {
      if (binary_search(begin(A), end(A), A.size()))
        cout << total - A.size();
      else
        cout << total;
      cout << '\n';
    }
  }
}