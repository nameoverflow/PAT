#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;
#define LOG(__t) cout << ""#__t": " << __t << endl

set<int> g[220];
bool visited[220];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int f, t;
    cin >> f >> t;
    g[f].insert(t);
    g[t].insert(f);
  }

  cin >> m;
  for (int _ = 0; _ < m; _++) {
    int k;
    cin >> k;
    int pre, cur, first;
    cin >> pre;
    first = pre;
    bool res = k == n + 1;
    set<int> vis{ pre };
    for (int i = 1; i < k; i++) {
      cin >> cur;
      res = res && g[pre].find(cur) != g[pre].end();
      // LOG(!visited[cur]);
      // LOG((g[pre].find(cur) != g[pre].end()));
      vis.insert(cur);
      pre = cur;
    }
    res = res && vis.size() == n && pre == first;
    if (res) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
