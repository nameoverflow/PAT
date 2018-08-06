#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
#include <queue>

using namespace std;

struct E {
  int fr, to, d;
};

vector<E> g[1010];
vector<E> ng[1010];
int deg[1010];
set<int> nd;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int f, t, d;
    cin >> f >> t >> d;
    g[f].push_back({ f, t, d });
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
      if (deg[nxt.to] > 0) {
        deg[nxt.to]--;
        if (deg[nxt.to] == 0) pre.insert(nxt.to);
      }
    }
  }

  if (nd.empty()) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl << nd.size();
    return;
  }

}
