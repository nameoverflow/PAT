#include <cstdio>
#include <iostream>
#include <utility>
#include <queue>
#include <functional>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

using ull = unsigned long long;
using PLL = pair<ull, ull>;

#define MP make_pair
#define se second
#define fi first

// struct E {
//   int to;
//   ull n = 0, di = 1;
// };

vector<int> g[100010];
// E ed[1000100];

bool vis[100010] = {0};
// ull dist[100010];
// ull dijks(int st, int en, int n) {
//   priority_queue<PLL, vector<PLL>, greater<PLL>> pq;

//   fill(vis, vis + n, 0);
//   fill(dist, dist + n, ULLONG_MAX - 10);

//   dist[st] = 0;
//   vis[st] = 1;
//   pq.push(MP(0, st));

//   while (pq.size()) {
//     auto u = pq.top().se, du = pq.top().fi; pq.pop();
//     if (u == en) break;
//     for (size_t i = g[u]; i; i = ed[i].n) {
//       if (vis[ed[i].to]) continue;
//       auto dv = dist[u] + ed[i].di;
//       if (dv < dist[ed[i].to]) {
//         dist[ed[i].to] = dv;
//         vis[ed[i].to] = true;
//         pq.push(MP(dv, ed[i].to));
//       }
//     }
//   }

//   return dist[en];
// }

ull minp = ULLONG_MAX;
int minr = 0;
void dfs(int cur, ull dep) {
  if (g[cur].size() == 0) {
    if (dep < minp) {
      minp = dep;
      minr = 1;
    } else if (dep == minp) {
      minr++;
    }
    return;
  }
  vis[cur] = 1;
  for (auto n : g[cur]) {
    if (!vis[n]) {
      dfs(n, dep + 1);
    }
  }
  vis[cur] = 0;
}

int main() {
  int n;
  double p, r;
  scanf("%d %lf %lf", &n, &p, &r);

  for (size_t i = 0, ei = 1; i < n; i++) {
    int k;
    scanf("%d", &k);
    while (k--) {
      int to;
      scanf("%d", &to);
      // ed[ei].n = g[i];
      // ed[ei].to = to;
      // g[i] = ei;
      // ei++;
      g[i].push_back(to);
    }
  }

  dfs(0, 0);
  printf("%.04lf %d", p * pow(1 + r / 100, minp), minr);
}

