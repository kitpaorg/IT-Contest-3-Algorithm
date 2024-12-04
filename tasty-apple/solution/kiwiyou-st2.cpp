#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int32_t N, Q;
  cin >> N >> Q;
  if (N > 500)
    return 0;
  vector<pair<int32_t, int32_t>> apple(N);
  for (auto &[ti, _] : apple)
    cin >> ti;
  for (auto &[_, si] : apple)
    cin >> si;
  for (int32_t i = 0; i < Q; ++i) {
    int32_t p;
    cin >> p;
    int32_t max_s = 0, max_count = 0;
    for (auto [ti, si] : apple) {
      if (ti < p)
        continue;
      if (max_s < si) {
        max_s = si;
        max_count = 1;
      } else if (max_s == si)
        max_count++;
    }
    cout << max_count << '\n';
  }
}
