#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

using ll = long long;

int main() {
  int n;
  cin >> n;
  set<ll> numset;
  ll maxn = -1;
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    if (num <= 0) continue;
    maxn = max(maxn, num);
    numset.insert(num);
  }

  int pre = 0;
  for (auto nn : numset) {
    if (pre + 1 != nn) {
      cout << pre + 1;
      break;
    }
    pre = nn;
  }

  if (numset.empty()) cout << 1;


}
#if 0
// bool bnum[10000010];

int main() {
  int n;
  cin >> n;
  ll l = 0, r = LONG_MAX;
  for (int i = 0; i < n; i++) {
    ll num;
    cin >> num;
    if (num <= 0) continue;

  }

  for (ll i = 1; i < maxn; i++) {
    if (!bnum[i]) {
      cout << i;
      break;
    }
  }
}
#endif