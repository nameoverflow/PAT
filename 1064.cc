#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

struct T {
  int l = -1, r = -1;
  int n;
};

int cnt[1010];
T tr[1010];

void build(int n) {
  for (int i = 1;; i++) {
    if (i * 2 >= n + 1) break;
    tr[i].l = i * 2;
    if (i * 2 + 1 >= n + 1) break;
    tr[i].r = i * 2 + 1;
  }
}

void dfs(int r) {
  static int i = 0;
  if (r == -1) return;
  dfs(tr[r].l);
  tr[r].n = cnt[i++];
  dfs(tr[r].r);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cnt[i];
  }
  sort(cnt, cnt + n);
  // int comp = 1;
  // while ((comp << 1) <= n) comp <<= 1;
  build(n);
  dfs(1);
  queue<int> q;
  bool flag = 1;
  q.push(1);
  while (q.size()) {
    auto cc = q.front(); q.pop();
    if (cc == -1) continue;
    if (!flag) cout << " ";
    else flag = 0;
    cout << tr[cc].n;
    q.push(tr[cc].l);
    q.push(tr[cc].r);
  }

  return 0;
}

