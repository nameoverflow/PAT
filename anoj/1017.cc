#include <vector>
#include <set>
#include <utility>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>


// #include <sys/time.h>

#define PII pair<int, int>
#define MP make_pair
#define fi first
#define se second

using namespace std;

struct PT {
  int x, y, r;
};

double g[1010][1010];
PT ar[1010];

double dist[1010];
bool vis[1010] = {0};

// int f[1010];
// int find(int x) {
//   while ((x = f[x]) != f[x]);
//   return x;
// }

// void join(int x, int y) {
//   f[find(x)] = f[find(y)];
// }

void dijks(int st, int ed, int n) {
  using PDI = pair<double, int>;
  priority_queue<PDI, vector<PDI>, greater<PDI>> pq;
  dist[st] = 0;
  vis[st] = 1;
  pq.push(MP(0, st));
  while (pq.size()) {
    int u = pq.top().se;
    double du = pq.top().fi;
    pq.pop();
    vis[u] = true;
    if (u == ed) return;
    // for (auto &e : g[u]) {
    for (int i = 0; i < n; i++) {
      if (vis[i]) continue;
      double dv = dist[u] + g[u][i];
      if (dv < dist[i]) {
        dist[i] = dv;
        pq.push(MP(dv, i));
      }
    }
  }
}

int main() {

//   struct timeval  tv1, tv2;
//   gettimeofday(&tv1, NULL);
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y, r;
    scanf("%d %d %d", &ar[i].x, &ar[i].y, &ar[i].r);
  }
  scanf("%d %d", &ar[n].x, &ar[n].y); ar[n].r = 0;
  scanf("%d %d", &ar[n + 1].x, &ar[n + 1].y); ar[n + 1].r = 0;

  for (int i = 0; i < n + 2; i++) {
    // g[i].reserve(n + 2);
    for (int j = 0; j < i; j++) {
      double dx = (double)ar[i].x - (double)ar[j].x;
      double dy = (double)ar[i].y - (double)ar[j].y;
      double dis = sqrt(pow(dx, 2) + pow(dy, 2));
      dis = max(0.0, dis - ar[i].r - ar[j].r);
      g[i][j] = dis;
      g[j][i] = dis;
    }
    g[i][i] = INFINITY;
  }

  fill(dist, dist + n + 2, INFINITY);
  dijks(n, n + 1, n + 2);
  printf("%.2lf", dist[n + 1]);
//   gettimeofday(&tv2, NULL);

//   printf ("\nTotal time = %f seconds\n",
//          (double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +
//          (double) (tv2.tv_sec - tv1.tv_sec));
}