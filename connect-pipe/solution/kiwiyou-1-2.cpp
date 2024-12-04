#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector pipe(2, string());
  cin >> pipe[0] >> pipe[1];
  auto is_l = [](const auto &c) {
    return c == 'L';
  };
  if (all_of(begin(pipe[0]) + 1, end(pipe[0]), is_l)
      && all_of(begin(pipe[1]), end(pipe[1]) - 1, is_l))
    cout << "YES\n";
  else
    cout << "NO\n";
}
