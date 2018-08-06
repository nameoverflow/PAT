#include <vector>
#include <cstring>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <climits>
#include <functional>
#include <algorithm>
#include <cmath>

using namespace std;

using PII = pair<int, int>;
#define fi first
#define se second
#define MP make_pair

int dist[1050];
bool vis[1050] = {0};
vector<PII> g[1050];
int N, M, K, Ds;

void dijk(int st) {
  fill(dist, dist + N + M + 10, INT_MAX);
  // fill(vis, vis + N + M + 10, 0);

  priority_queue<PII, vector<PII>, greater<PII>> pq;
  dist[st] = 0;
  // vis[st] = 1;
  pq.push(MP(0, st));

  while (pq.size()) {
    auto u = pq.top().se, du = pq.top().fi;
    pq.pop();
    if (du > dist[u]) continue;
    for (auto &e : g[u]) {
      // if (e.se > N) continue;
      if (dist[u] + e.fi < dist[e.se]) {
        dist[e.se] = du + e.fi;
        // vis[e.se] = 1;
        pq.push(MP(dist[e.se], e.se));
      }
    }
  }
}

int cov(string &d) {
  if (d[0] != 'G') return stoi(d);
  return atoi(d.c_str() + 1) + N;
}

int main() {
  cin >> N >> M >> K >> Ds;
  for (int i = 0; i < K; i++) {
    string fs, ts; int d;
    cin >> fs >> ts >> d;
    int fr = cov(fs), to = cov(ts);
    g[fr].push_back(MP(d, to));
    g[to].push_back(MP(d, fr));
  }

  double minsum = INFINITY;
  double mindis = 0;
  int best = 0;
  for (int i = 1; i < M + 1; i++) {
    dijk(i + N);
    bool ok = true;
    double sum = 0, mind = INFINITY;
    for (int j = 1; j < N + 1 && ok; j++) {
      // cout << dist[j] << " ";
      ok = dist[j] <= Ds;
      sum += dist[j];
      mind = min(mind, 1.0 * dist[j]);
    }
      // cout << endl;
    if (ok && (mind > mindis || (mind == mindis && sum < minsum))) {
      best = i;
      mindis = mind;
      minsum = sum;
    }
  }

  if (best) {
    printf("G%d\n%.1lf %.1lf", best, mindis, 1.0 * minsum / N);
  } else {
    printf("No Solution");
  }
}