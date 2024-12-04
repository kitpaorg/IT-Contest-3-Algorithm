#include <algorithm>
#include <cstdint>
#include <functional>
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
  sort(begin(apple), end(apple), greater());
  vector<pair<int32_t, int32_t>> query;
  for (int32_t i = 0; i < Q; ++i) {
    int32_t p;
    cin >> p;
    query.emplace_back(p, i);
  }
  sort(begin(query), end(query), greater());
  int32_t j = 0, max_s = 0, max_count = 0;
  vector<int32_t> answer(Q);
  for (auto [p, i] : query) {
    while (j < N && apple[j].first >= p) {
      int sj = apple[j].second;
      if (max_s < sj) {
        max_s = sj;
        max_count = 1;
      } else if (max_s == sj)
        max_count++;
      j++;
    }
    answer[i] = max_count;
  }
  for (auto ai : answer)
    cout << ai << '\n';
}
