#include <cstdio>
#include <vector>
#include <climits>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAXN (550)
using PII = pair<int, int>;

struct E {
  int to, di;
  int n = 0;
};

vector<int> pre[MAXN];
int g[MAXN] = {0};
E edge[MAXN * MAXN / 2];
int dist[MAXN];
// int level[MAXN];
int cnt[MAXN];

bool vis[MAXN] = {0};
int N;
int m, l, k, s, t;


void dijkst(int st) {
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  fill(dist, dist + N, INT_MAX - 10);
  // fill(vis, vis + N, 0);

  dist[st] = 0;
  // vis[st] = 1;
  pq.push({ 0, st });

  while (pq.size()) {
    auto u = pq.top().second, du = pq.top().first;
    pq.pop();
    if (du > dist[u]) continue;
    for (int ei = g[u]; ei; ei = edge[ei].n) {
      auto dv = du + edge[ei].di;
      auto v = edge[ei].to;
      // printf("%d %d\n", v, dv);
      if (dv < dist[v]) {
        dist[v] = dv;
        pre[v] = { u };
        pq.push({ dv, v });
      } else if (dv == dist[v]) {
        pre[v].push_back(u);
      }
    }
  }
}

int level[MAXN] = {0};
void getlv(int r) {
  queue<PII> q;
  fill(level, level + N, INT_MAX - 10);
  fill(vis, vis + N, 0);

  level[r] = 0;
  vis[r] = 1;
  q.push({ 0, r });

  while (q.size()) {
    auto u = q.front().second, du = q.front().first;
    q.pop();
    for (int ei = g[u]; ei; ei = edge[ei].n) {
      auto dv = du + 1;
      auto v = edge[ei].to;
      if (!vis[v] && dv < dist[v]) {
        vis[v] = 1;
        dist[v] = dv;
        q.push({ dv, v });
      }
    }
  }
}

// vector<vector<int>> paths;
int maxrest = 0;
int minhalf = INT_MAX;
int pathc = 0;
vector<int> minpath;
void selpath(int st, int en, vector<int> &cp) {
  cp.push_back(en);
  vis[en] = 1;
  if (pre[en].size() == 0 && en == st) {
    pathc++;
    int rest = 0, halfval = 0;;
    int half = floor(cp.size() / 2.0);
    for (int i = 0; i < cp.size(); i++) {
      rest += cnt[cp[i]];
      if (i < half) {
        halfval += cnt[cp[i]];
      }
    }
    rest = rest % k;
    if (rest > maxrest || (rest == maxrest && halfval < minhalf)) {
      minpath = cp;
      maxrest = rest;
      minhalf = halfval;
    }
  }
  for (auto n : pre[en]) {
    // printf("%d -> %d\n", en, n);
    if (vis[n]) continue;
    selpath(st, n, cp);
  }
  vis[en] = 0;
  cp.pop_back();
}


int main() {
  scanf("%d %d %d %d %d %d", &N, &m, &l, &k, &s, &t);
  for (int i = 0; i < N; i++) {
    scanf("%d", &cnt[i]);
  }
  for (int i = 0, ei = 1; i < m; i++) {
    int f, t, d;
    scanf("%d %d %d", &f, &t, &d);
    edge[ei].to = t;
    edge[ei].di = d;
    edge[ei].n = g[f];
    g[f] = ei;
    ei++;
    edge[ei].to = f;
    edge[ei].di = d;
    edge[ei].n = g[t];
    g[t] = ei;
    ei++;
  }

  getlv(s);
  dijkst(s);


  if (!pre[t].size()) {
    printf("-1");
    return 0;
  }

  for (int i = 0; i < N; i++) {
    if (level[i] < l) {
      cnt[i] = ceil((double)cnt[i] * (1.0 + (1.0 / l) * (l - level[i])));
    }
  }
  vector<int> hh;
    fill(vis, vis + N, 0);

  selpath(s, t, hh);

  printf("%d %d %d %d\n", pathc, dist[t], maxrest, minhalf);
  auto it = minpath.rbegin();
  printf("%d", *(it++));
  for (; it != minpath.rend(); it++) {
    printf("->%d", *it);
  }
}
