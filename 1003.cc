#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <cassert>

#define fi first
#define se second
#define MP make_pair

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define LOG(__t) cout << ""#__t": " << __t << endl
#define MAXN (500+10)

typedef pair<ull, pair<ull, ull>> E;



vector<E> g[MAXN];
ull dist[MAXN];
ull teams[MAXN];
ull paths[MAXN] = {0};
ull maxr[MAXN] = {0};
ull N, M, C1, C2;
int dijkstra(ull s) {
  priority_queue<E, vector<E>, greater<E>> pq;
  for (auto &e : g[s]) {
    pq.push(e);
  }
  dist[s] = 0;
  while (!pq.empty()) {
    auto cur = pq.top(); pq.pop();
    ull nc = cur.fi + dist[cur.se.fi];
    if (nc < dist[cur.se.se]) {
      dist[cur.se.se] = nc;
      for (auto &e : g[cur.se.se]) {
        pq.push(e);
      }
    }
  }
}

vector<ull> ng[MAXN];
ull deg[MAXN] = {0};

int search(ull s) {
  for (int i = 0; i < N; i++) {
    for (auto &e : g[i]) {
      if (dist[e.se.se] == e.fi + dist[i]) {
        ng[i].push_back(e.se.se);
        deg[e.se.se]++;
      }
    }
  }
  queue<ull> q;
  maxr[s] = teams[s];
  paths[s] = 1;

  for (int i = 0; i < N; i++) {
    if (!deg[i]) q.push(i);
  }
  while (q.size()) {
    auto i = q.front(); q.pop();
    for (auto &nxt : ng[i]) {
      if (maxr[nxt] < maxr[i] + teams[nxt]) {
        maxr[nxt] = maxr[i] + teams[nxt];
      }
      paths[nxt] += paths[i];
      deg[nxt]--;
      if (!deg[nxt]) {
        q.push(nxt);
      }
    }
  }

}

int main() {
  for (ull i = 0; i < MAXN; i++) {
    dist[i] = ULLONG_MAX - 10;
  }
  scanf("%lld %lld %lld %lld", &N, &M, &C1, &C2);
  for (ull i = 0; i < N; i++) {
    scanf("%lld", &teams[i]);
  }
  for (ull i = 0; i < M; i++) {
    ull f, e, c;
    scanf("%d %d %d", &f, &e, &c);
    g[f].push_back(MP(c, MP(f, e)));
    g[e].push_back(MP(c, MP(e, f)));
  }

  dijkstra(C1);
  search(C1);

  printf("%d %d", paths[C2], maxr[C2]);
}