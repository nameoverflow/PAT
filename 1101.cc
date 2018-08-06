#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <climits>

#define MAXN (100010)

using namespace std;

int all[MAXN];
int minn[MAXN];
int maxn[MAXN];

int main() {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  if (n < 1) {
    cout << "0";
    return 0;
  }
  fill(minn, minn + n, INT_MAX);
  cin >> all[0];
  maxn[0] = all[0];
  for (int i = 1; i < n; i++) {
    cin >> all[i];
    maxn[i] = max(maxn[i - 1], all[i]);
  }

  minn[n - 1] = all[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    minn[i] = min(all[i], minn[i + 1]);
  }
  set<int> res;
  for (int i = 0; i < n; i++) {
    if (maxn[i] <= all[i] && minn[i] >= all[i]) res.insert(all[i]);
  }

  cout << res.size() << endl;
  // cout << "fuck\n";
  if (res.empty()) {
    cout << '\n';
    return 0;
  }
  // while(res.empty());
  auto it = res.begin();
  cout << *(it++);
  for (; it != res.end(); it++) {
    cout << " " << *it;
  }
}
