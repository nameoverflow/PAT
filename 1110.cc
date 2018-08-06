#include <utility>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;

#define MP make_pair
#define fi first
#define se second

PII tr[22];
int pa[22];
int main() {
  int n;
  scanf("%d", &n);
  
  fill(tr, tr + n, MP(-1, -1));
  fill(pa, pa + n, -1);
  for (int i = 0; i < n; i++) {
    char a[10], b[10];
    scanf("%s %s", a, b);
    if (a[0] != '-') {
      tr[i].fi = atoi(a);
      pa[tr[i].fi] = i;
    }
    if (b[0] != '-') {
      tr[i].se = atoi(b);
      pa[tr[i].se] = i;
    }
  }

  int root = 0;
  while (pa[root] != -1) root = pa[root];

  int last = 0;
  int lv = 0;
  bool flag = 0;
  bool comp = 1;
  queue<int> q;
  q.push(root);
  while (q.size()) {
    auto cur = q.front(); q.pop();
    if (cur == -1) continue;
    last = cur;
    if (tr[cur].fi == -1) {
      flag = 1;
    } else {
      if (flag) comp = 0;
    }
    if (tr[cur].se == -1) {
      flag = 1;
    } else {
      if (flag) comp = 0;
    }
    if (!comp) break;
    q.push(tr[cur].fi);
    q.push(tr[cur].se);
  }

  if (comp) {
    printf("YES %d", last);
  } else {
    printf("NO %d", root);
  }
}
