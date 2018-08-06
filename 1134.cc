#include <utility>
#include <vector>
#include <cstdio>

using namespace std;

#define PI pair<int, int>

vector<int> g[10010];
bool cov[10010];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int f, t;
    scanf("%d %d", &f, &t);
    g[f].push_back(i);
    g[t].push_back(i);
  }

  int k;
  scanf("%d", &k);
  for (int _ = 0; _ < k; _++) {
    int nv;
    scanf("%d", &nv);
    fill(cov, cov + m, 0);
    for (int i = 0; i < nv; i++) {
      int v;
      scanf("%d", &v);
      for (auto &e: g[v]) {
        cov[e] = true;
      }
    }
    bool res = true;
    for (int i = 0; i < m; i++) {
      res = res && cov[i];
    }
    if (res) puts("Yes");
    else puts("No");
  }
}
