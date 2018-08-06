#include <vector>
#include <cstdio>
#include <queue>
#include <set>
#include <utility>
#include <map>
#include <functional>
#include <algorithm>
#include <cstring>
#include <climits>

using namespace std;

using ull = unsigned long long;
using P = pair<ull, ull>;
#define MP make_pair

// map<ull, vector<ull>> g;
// map<ull, vector<ull>> ng;
struct E {
  ull to, di;
};
vector<E> g[1000010];
vector<E> ng[1000010];
ull dist[1000010];
set<ull> init, tgt;
int N;

ull dij(ull st, vector<E> gg[]) {
  priority_queue<P, vector<P>, greater<P>> pq;
  memset(dist, 0xff, (N + 1) * sizeof(ull));

  pq.push(MP(0, st));
  dist[st] = 0;

  while (pq.size()) {
    auto u = pq.top().second, du = pq.top().first;
    // printf("%llu : %llu\n", u, du);
    pq.pop();
    if (du > dist[u]) continue;
    for (auto &ei : gg[u]) {
      ull dv = dist[u] + ei.di;
      if (dv < dist[ei.to]) {
        dist[ei.to] = dv;
        pq.push(MP(dv, ei.to));
      }
    }
  }
} 

void solve() {
  ull total = 0;
  ull maxe = 0;
  // for (auto k : tgt) {
  //   total += dij(k, ng, init);
  //   auto ee = dij(k, g, init);
  //   total += ee;
  //   maxe = max(ee, maxe);
  // }
  
  dij(0, g);
  for (auto k : tgt) {
    total += dist[k];
    // printf("%llu\n", dist[k]);
  }
  dij(0, ng);
  for (auto k : tgt) {
    total += dist[k];
    maxe = max(maxe, dist[k]);
    // printf("%llu\n", dist[k]);
  }
  printf("%llu", total - maxe);
}

int main() {
  ull M, P, K;
  scanf("%llu %llu %llu %llu", &N, &M, &P, &K);
  for (ull i = 0; i < P; i++) {
    ull t;
    scanf("%llu", &t);
    init.insert(t);
  }
  for (ull i = 0; i < K; i++) {
    ull t;
    scanf("%llu", &t);
    tgt.insert(t);
  }
  for (ull i = 1; i < M + 1; i++) {
    ull u, v, w;
    scanf("%llu %llu %llu", &u, &v, &w);
    g[u].push_back({ v, w });
    ng[v].push_back({ u, w });
  }

  for (auto t : init) {
    g[0].push_back({ t, 0 });
    ng[0].push_back({ t, 0 });
  }

  solve();
}


