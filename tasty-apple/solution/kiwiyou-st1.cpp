#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int32_t N, Q, t;
  cin >> N >> Q >> t;
  for (int32_t i = 1; i < N; ++i) {
    int32_t ti;
    cin >> ti;
    if (ti != t)
      return 0;
  }
  int max_s = 0;
  int max_count = 0;
  for (int i = 0; i < N; ++i) {
    int si;
    cin >> si;
    if (max_s < si) {
      max_s = si;
      max_count = 1;
    } else if (max_s == si)
      max_count++;
  }
  for (int32_t i = 0; i < Q; ++i) {
    int32_t p;
    cin >> p;
    cout << (p > t ? 0 : max_count) << '\n';
  }
}
