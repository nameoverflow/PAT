#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <iostream>

using namespace std;

#define PII pair<int, int>
#define MP make_pair
#define fi first
#define se second

#define REP(__i, __n) for (size_t i = 0; i < __n; __i++)
#define REP1(__i, __n) for (size_t i = 1; i < __n + 1; __i++)
#define LOG(__v) cout << #__v": " << __v << endl

PII tr[22];
int cn[22];
int pa[22];
vector<int> res {0};

int unb = 0;
int bal(int r) {
  if (r == -1) return 0;
  auto hl = bal(tr[r].fi);
  auto hr = bal(tr[r].se);
  if (abs(hl - hr) > 1) {
    unb++;
  }
  return max(hl, hr) + 1;
}

int cl = 1;
bool cp(int root) {
  queue<PII> q;
  q.push(MP(root, 1));
  bool flag = 0;
  while (q.size()) {
    auto cur = q.front(); q.pop();
    if (cur.fi == -1) continue;
    // LOG(cur.fi);
    // LOG(tr[cur.fi].fi);
    // LOG(tr[cur.fi].se);
    res.push_back(cn[cur.fi]);
    if (!flag) cl = cur.se;
    q.push(MP(tr[cur.fi].fi, cur.se + 1));
    q.push(MP(tr[cur.fi].se, cur.se + 1));
    if (tr[cur.fi].fi == -1) {
      flag = 1;
    } else {
      if (flag == 1) {
        return false;
      }
    }
    if(tr[cur.fi].se == -1) {
      flag = 1;
    } else {
      if (flag == 1) return false;
    }
    // if (q.front().se > cur.se || q.empty()) cl = cur.se;
  }
  return true;
}

int mv = 0;
void lift(int r, int n) {
  int cur = res[r];
  int nmax = r;

  while (r * 2 < n || r * 2 + 1 < n) {
    if (r * 2 < n && res[nmax] < res[r * 2]) {
      nmax = r * 2;
    }
    if (r * 2 + 1 < n && res[nmax] < res[r * 2 + 1]) {
      nmax = r * 2 + 1;
    }
    if (nmax != r) {
      swap(res[r], res[nmax]);
      mv++;
      r = nmax;
    } else break;
  }

}

int main() {
  int n;
  scanf("%d", &n);
  fill(tr, tr + n + 1, MP(-1, -1));
  fill(pa, pa + n + 1, -1);
  REP1(i, n) {
    scanf("%d", &cn[i]);
  }
  REP1(i, n) {
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
    // LOG(i);
    // LOG(tr[i].fi);
    // LOG(tr[i].se);
  }

  int root = 1;
  while (pa[root] != -1) root = pa[root];

  bal(root);
  if (unb > 0) {
    printf("NOT AVL TREE!!!\n%d", unb);
    return 0;
  }

  if(!cp(root)) {
    printf("NOT COMPLETE TREE!!!\n%d", cl);
    return 0;
  }

  // for(auto v:res) LOG(v);
  for (int i = res.size() / 2 - 1; i > 0; i--) {
    lift(i, res.size());
  }
  // lift(1, res.size());
  // for(auto v:res) LOG(v);
  printf("OHHHHH HEAP!!!\n%d", mv);

}

