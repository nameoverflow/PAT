#include <utility>
#include <vector>
#include <climits>
#include <queue>
#include <functional>

using namespace std;

using PII = pair<int, int>;
#define MP make_pair
#define fi first
#define se second

struct E {
  int fr, to;
  int ti, di;
  int n = 0;
};

int g[505];
E e[505 * 505];

int dist[505], dtime[505];
bool visit[505];
// vector<int> dpath[505], tpath[505];
int dpath[505], tpath[505];

int dijkst(int st, int ed, int n) {
  fill(dtime, dtime + n, INT_MAX - 10);
  fill(visit, visit + n, 0);
  dtime[st] = 0;
  visit[st] = 1;
  tpath[st] = -1;
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  for (int i = g[st]; i; i = e[i].n) {
    pq.push(MP(e[i].ti, i));
    tpath[e[i].to] = { st };
  }

  while (pq.size()) {
    auto f = e[pq.top().se].fr;
    auto u = e[pq.top().se].to;
    auto du = pq.top().fi;
    pq.pop();
    // printf("%d %d %d\n", f, u, du);
    if (du > dtime[u]) continue;
    visit[u] = 1;
    if (du == dtime[u]) {
      int s1 = 0, s2 = 0;
      for (int j = f; j >= 0; j = tpath[j]) s1++;
      for (int j = u; j >= 0; j = tpath[j]) s2++;
      if (s1 + 1 > s2) continue;
    }
    tpath[u] = f;
    swap(dtime[u], du);
    if (dtime[u] == du) continue;
    // if (u == ed) break;
    for (int i = g[u]; i; i = e[i].n) {
      auto dv = dtime[u] + e[i].ti;
      if (!visit[e[i].to] && dv < dtime[e[i].to]) {
        pq.push(MP(dv, i));
      } else if (dv == dtime[i]){
        pq.push(MP(dv, i));
      }
    }
  }
  return dtime[ed];
}
int dijksd(int st, int ed, int n) {
  fill(dist, dist + n, INT_MAX - 10);
  fill(visit, visit + n, 0);
  dist[st] = 0;
  visit[st] = 1;
  dpath[st] = -1;
  priority_queue<PII, vector<PII>, greater<PII>> pq;
  for (int i = g[st]; i; i = e[i].n) {
    pq.push(MP(e[i].di, i));
    dpath[e[i].to] = st;
  }

  while (pq.size()) {
    auto f = e[pq.top().se].fr;
    auto u = e[pq.top().se].to;
    auto du = pq.top().fi;
    auto ddu = e[pq.top().se].ti;
    pq.pop();
    if (du > dist[u]) continue;
    // printf("%d %d %d\n", f, u, du);
    visit[u] = 1;
    if (du == dist[u] && dtime[f] + ddu > dtime[u]) continue;
    dpath[u] = f;
    swap(dist[u], du);
    if (dist[u] == du) continue;
    // if (u == ed) break;
    for (int i = g[u]; i; i = e[i].n) {
      auto dv = dist[u] + e[i].di;
      if (!visit[e[i].to] && dv < dist[e[i].to]) {
        pq.push(MP(dv, i));
      } else if (dv == dist[i]) {
        pq.push(MP(dv, i));
      }
    }
  }
  return dist[ed];
}


int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int ei = 1;
  while (m--) {
    int ow, u, v, d, t;
    scanf("%d %d %d %d %d", &u, &v, &ow, &d, &t);
    e[ei].fr = u; e[ei].to = v;
    e[ei].di = d; e[ei].ti = t;
    e[ei].n = g[u];
    g[u] = ei;
    ei++;
    if (!ow) {
      e[ei].fr = v; e[ei].to = u;
      e[ei].di = d; e[ei].ti = t;
      e[ei].n = g[v];
      g[v] = ei;
      ei++;
    }
  }

  int st, ed;
  scanf("%d %d", &st, &ed);

  int ttm = dijkst(st, ed, n);
  int dist = dijksd(st, ed, n);
  vector<int> dp, tp;
  for (int j = dpath[ed]; j >= 0; j = dpath[j]) dp.push_back(j);
  for (int j = tpath[ed]; j >= 0; j = tpath[j]) tp.push_back(j);

  bool eq = true;
  if (dp.size() == tp.size()) {
    for (int i = 0; i < dp.size(); i++) {
      eq = dp[i] == tp[i];
      if (!eq) break;
    }
  } else eq = false;
  if (eq) {
    printf("Distance = %d; Time = %d: ", dist, ttm);
    for (auto i = dp.rbegin(); i != dp.rend(); i++) {
      printf("%d -> ", *i);
    }
    printf("%d", ed);
    return 0;
  }
  printf("Distance = %d: ", dist);
  for (auto i = dp.rbegin(); i != dp.rend(); i++) {
    printf("%d -> ", *i);
  }
  printf("%d\n", ed);
  printf("Time = %d: ", ttm);
  for (auto i = tp.rbegin(); i != tp.rend(); i++) {
    printf("%d -> ", *i);
  }
  printf("%d", ed);
}
