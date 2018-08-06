#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
#include <vector>

#define PII pair<int, int>
#define MP make_pair
#define REPF(_i, _s, _n) for (size_t _i = _s; _i < _n; _i++)
#define fi first
#define se second

using namespace std;

int in[33];
int po[33];
PII tr[33];

int build(int ins, int pos, int len) {
  if (len < 1) return -1;
  int pt = pos + len - 1;
  int i = ins;
  for (; i < ins + len; i++) {
    if (in[i] == po[pt]) break;
  }
  int nl = i - ins;
  int l = build(ins, pos, nl);
  int r = build(i + 1, pos + nl, len - nl - 1);
  tr[pt].fi = l;
  tr[pt].se = r;
  return pt;
}

int main() {
  int n;
  cin >> n;
  fill(tr, tr + 1 + n, MP(-1, -1));
  REPF(i, 1, n + 1) {
    cin >> in[i];
  }
  REPF(i, 1, n + 1) {
    cin >> po[i];
  }

  int t = build(1, 1, n);
  vector<PII> fl;
  fl.reserve(n);
  deque<PII> o;
  o.push_back(MP(t, 1));
  while (o.size()) {
    auto cur = o.front(); o.pop_front();
    if (cur.fi < 1) continue;
    fl.push_back(cur);
    o.push_back(MP(tr[cur.fi].fi, cur.se + 1));
    o.push_back(MP(tr[cur.fi].se, cur.se + 1));
  }

  cout << po[fl[0].fi];
  for (int i = 1; i < n; i++) {
    if (fl[i].se % 2 == 0) {
      for (;i < n; i++) {
        cout << " " << po[fl[i].fi];
        if (fl[i].se != fl[i + 1].se) break;
      }
    } else {
      int c = i;
      while (i < n && fl[i].se == fl[i + 1].se) i++;
      for (int j = i; j >= c; j--) cout << " " << po[fl[j].fi];
    }
  }
}
