// #include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cinttypes>
#include <climits>
#include <cstdio>

using namespace std;

struct E {
  int f, t, l;
};

struct S {
  int id;
  vector<int> e;
};

S g[10010];
int dist[10010];
int tran[10010];
vector<int> pree[10010];
vector<E> ed;
int n;

#define INF (INT_MAX - 100)

void bfs(int ori) {
  fill(dist, dist + 10010, INF);
  for (int i = 0; i < 10010; i++) pree[i].clear();
  fill(tran, tran + 10010, 0);
  queue<int> q;
  
  dist[ori] = 0;
  for (auto &e : g[ori].e) {
    q.push(e);
  }

  while (q.size()) {
    auto e = q.front(); q.pop();
    auto &d = dist[ed[e].t];
    auto nd = dist[ed[e].f] + 1;
    if (d > nd) {
      d = nd;
      pree[ed[e].t] = { e };
      for (auto &n : g[ed[e].t].e) {
        q.push(n);
      }
    } else if (d == nd) {
      pree[ed[e].t].push_back(e);
    }
  }
}

vector<int> bestp;
vector<int> tmpp;
int mint = INT_MAX;
void dfsinit() {
  tmpp.clear();
  mint = INT_MAX;
}
void dfs(int r) {
  if (pree[r].empty()) {
    int tmpt = 0;
    int lastl = ed[tmpp[0]].l;
    for (auto ei : tmpp) {
      tmpt += lastl != ed[ei].l;
      lastl = ed[ei].l;
    }
    if (tmpt < mint) {
      bestp = tmpp;
      mint = tmpt;
    }
  }
  for (auto &e : pree[r]) {
    tmpp.push_back(e);
    dfs(ed[e].f);
    tmpp.pop_back();
  }
}

void dump(int to) {
  printf("%d\n", bestp.size());
  auto p = ed[bestp.back()];
  bestp.pop_back();
  auto line = p.l;
  printf("Take Line#%d from %04d", p.l, p.f);
  if (to == p.t) {
    printf(" to %04d.\n", p.t);
  }
  while (bestp.size()) {
    p = ed[bestp.back()];
    bestp.pop_back();
    if (line != p.l) {
      printf(" to %04d.\nTake Line#%d from %04d", p.f, p.l, p.f);
      line = p.l;
    }
    if (to == p.t) {
      printf(" to %04d.\n", p.t);
    }
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n + 1; i++) {
    int ln, pre, nxt;
    scanf("%d", &ln);
    scanf("%d", &pre);
    for (int _ = 1; _ < ln; _++) {
      scanf("%d", &nxt);
      g[pre].e.push_back(ed.size());
      ed.push_back({ pre, nxt, i });
      g[nxt].e.push_back(ed.size());
      ed.push_back({ nxt, pre, i });
      pre = nxt;
    }
  }
  int k;
  scanf("%d", &k);
  for (int _ = 0; _ < k; _++) {
    int from, to;
    scanf("%d %d", &from, &to);
    bfs(from);
    dfsinit();
    dfs(to);
    dump(to);
  }
}
