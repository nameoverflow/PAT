#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>

using namespace std;

vector<int> g[1010];
int deg[1010];
set<int> nd;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int f, t;
    cin >> f >> t;
    g[f].push_back(t);
    deg[t]++;
  }

  set<int> pre;
  for (int i = 0; i < n; i++) {
    if (deg[i] == 0) pre.insert(i);
    nd.insert(i);
  }

  queue<int> res;

  while (pre.size()) {
    auto cur = *pre.begin();
    pre.erase(cur);
    nd.erase(cur);
    res.push(cur);
    for (auto nxt : g[cur]) {
      if (deg[nxt] > 0) {
        deg[nxt]--;
        if (deg[nxt] == 0) pre.insert(nxt);
      }
    }
  }

  if (nd.empty()) {
    cout << "YES" << endl;
    if (res.size()) {
      cout << res.front();
      res.pop();
    }

    while (res.size()) {
      cout << " " << res.front();
      res.pop();
    }
  } else {
    cout << "NO" << endl << nd.size();
  };

}
