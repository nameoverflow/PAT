#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define fi first
#define se second
#define PII pair<int, int>
#define MP make_pair

PII tr[22];
int da[22];


int height(int n)
{
  if (n == -1) return 0;
  return max(height(tr[n].fi), height(tr[n].se)) + 1;
}

int bal(int n)
{
  if (n == -1) return 0;
  return height(tr[n].fi) - height(tr[n].se);
}

int lr(int n)
{
  int t = tr[n].se;
  tr[n].se = tr[t].fi;
  tr[t].fi = n;
  return t;
}

int rr(int n)
{
  int t = tr[n].fi;
  tr[n].fi = tr[t].se;
  tr[t].se = n;
  return t;
}

int insert(int p, int n) {
  if (p == -1) return n;
  if (da[p] > da[n]) {
    tr[p].fi = insert(tr[p].fi, n);
    if (height(tr[p].fi) - height(tr[p].se) > 1) {
      if (da[n] > da[tr[p].fi]) {
        tr[p].fi = lr(tr[p].fi);
      }
      return rr(p);
    }
  } else {
    tr[p].se = insert(tr[p].se, n);
    if (height(tr[p].se) - height(tr[p].fi) > 1) {
      if (da[n] < da[tr[p].se]) {
        tr[p].se = rr(tr[p].se);
      }
      return lr(p);
    }
  }
  return p;
}

int main() {
  int n;
  cin >> n;
  int pt = -1;
  fill(tr, tr + n, MP(-1, -1));
  for (int i = 0; i < n; i++) {
    cin >> da[i];
    pt = insert(pt, i);
  }

  bool complete = 1;
  bool flag = 0;
  bool first = 1;
  queue<int> q;
  q.push(pt);
  while (q.size()) {
    auto c = q.front(); q.pop();
    if (first) {
      cout << da[c];
      first = false;
    } else {
      cout << " " << da[c];
    }
    if (tr[c].fi == -1) {
      flag = 1;
    } else {
      complete = !flag;
      q.push(tr[c].fi);
    }
    if (tr[c].se == -1) {
      flag = 1;
    } else {
      complete = !flag;
      q.push(tr[c].se);
    }
  }
  cout << '\n' << (complete ? "YES" : "NO");
}