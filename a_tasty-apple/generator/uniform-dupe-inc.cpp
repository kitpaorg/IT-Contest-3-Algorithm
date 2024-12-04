#include "testlib.h"
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  registerGen(argc, argv, 1);
  auto N = opt<int>("N");
  auto Q = opt<int>("Q");
  auto tmin = opt<int>("tmin", 1);
  auto tmax = opt<int>("tmax", 1e9);
  auto smin = opt<int>("smin", 1);
  auto smax = opt<int>("smax", 1e9);
  vector<int> t(N);
  for (auto &ti : t)
    ti = rnd.next(tmin, tmax);
  sort(begin(t), end(t));
  auto uniq = t;
  uniq.erase(unique(begin(uniq), end(uniq)), end(uniq));
  vector<pair<int, int>> interval;
  interval.emplace_back(1, uniq[0]);
  for (int i = 1; i < uniq.size(); ++i)
    interval.emplace_back(uniq[i - 1] + 1, uniq[i]);
  interval.emplace_back(uniq.back(), 1e9);
  vector<int> s(N);
  for (auto &si : s)
    si = rnd.next(smin, smax);
  sort(begin(s), end(s));
  auto order = rnd.distinct(N, N);
  vector<int> tt(N), ts(N);
  transform(begin(order), end(order), begin(tt), [&](auto i) { return t[i]; });
  transform(begin(order), end(order), begin(ts), [&](auto i) { return s[i]; });
  println(N, Q);
  println(tt);
  println(ts);
  for (int i = 0; i < Q; ++i) {
    auto [l, r] = rnd.any(interval);
    println(rnd.next(l, r));
  }
}
