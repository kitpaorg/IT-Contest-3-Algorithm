#include "testlib.h"
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
  registerValidation(argc, argv);
  auto N = inf.readInt(1, 200'000, "N");
  inf.readSpace();
  auto Q = inf.readInt(1, 200'000, "Q");
  inf.readEoln();
  auto t = inf.readInts(N, 1, 1'000'000'000, "t", 0);
  inf.readEoln();
  auto s = inf.readInts(N, 1, 1'000'000'000, "t", 0);
  inf.readEoln();
  vector<int> query;
  for (int i = 0; i < Q; ++i) {
    auto p = inf.readInt(1, 1'000'000'000, "p");
    inf.readEoln();
    query.push_back(p);
  }
  auto group = atoi(validator.group().c_str());
  switch (group) {
  case 1:
    ensure(count(begin(t), end(t), t[0]) == N);
    break;
  case 2:
    ensure(N <= 500);
    break;
  case 3:
    ensure(all_of(begin(t), end(t), [=](auto ti) { return ti <= 200'000; }));
    break;
  }
  inf.readEof();
}
