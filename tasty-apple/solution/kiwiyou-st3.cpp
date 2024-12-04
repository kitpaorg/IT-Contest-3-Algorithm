#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int32_t N, Q;
  cin >> N >> Q;
  vector<pair<int32_t, int32_t>> apple(N);
  for (auto &[ti, _] : apple)
    cin >> ti;
  for (auto &[_, si] : apple)
    cin >> si;
  vector<pair<int32_t, int32_t>> max_s_count(200'000);
  for (auto [ti, si] : apple) {
    if (ti > 200'000)
      return 0;
    auto &[max_s, max_count] = max_s_count[ti - 1];
    if (max_s < si) {
      max_s = si;
      max_count = 1;
    } else if (max_s == si)
      max_count++;
  }
  for (int i = 200'000; i-- > 1;) {
    auto &[p_max_s, p_max_count] = max_s_count[i];
    auto &[max_s, max_count] = max_s_count[i - 1];
    if (max_s < p_max_s) {
      max_s = p_max_s;
      max_count = p_max_count;
    } else if (max_s == p_max_s)
      max_count += p_max_count;
  }
  for (int32_t i = 0; i < Q; ++i) {
    int32_t p;
    cin >> p;
    if (p > 200'000)
      cout << "0\n";
    else
      cout << max_s_count[p - 1].second << '\n';
  }
}
