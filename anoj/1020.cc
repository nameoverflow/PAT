#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 1010;
using E = struct {
  int fr, to, di;
};
int deg[MAXN] = {0};
vector<E> g[MAXN];
set<int> nds;
vector<vector<int>> paths;
vector<int> topo;

int N, M;

bool topsort() {
  queue<int> prp;
  for (size_t i = 0; i < N; i++) {
    if (deg[i] == 0) prp.push(i);
  }
  int cur = -1;
  topo.reserve(N);
  while (prp.size()) {
    cur = prp.front();
    prp.pop();
    nds.erase(cur);
    topo.push_back(cur);

    for (auto &ne : g[cur]) {
      deg[ne.to]--;
      if (deg[ne.to] < 0) return false;
      if (deg[ne.to] == 0) {
        prp.push(ne.to);
      }
    }
  }
  if (cur < 0) return false;
  return true;
}

vector<int> way[MAXN];
static int dp[MAXN] = {0};

int solve() {
  int maxd = 0;
  for (auto it = topo.rbegin(); it != topo.rend(); it++) {
    auto n = *it;
    for (auto nxt : g[n]) {
      auto nd = dp[nxt.to] + nxt.di;
      if (nd > dp[n]) {
        dp[n] = nd;
        way[n] = { nxt.to };
      } else if (nd == dp[n]) {
        way[n].push_back(nxt.to);
      }
    }
    maxd = max(dp[n], maxd);
  }
  return maxd;
}

void dfs(int n) {
  static vector<int> tmpp;
  static int maxl = 0;
  tmpp.push_back(n);
  if (way[n].empty()) {
    paths.push_back(tmpp);
  }
  for (auto &ne : way[n]) {
    dfs(ne);
  }
  tmpp.pop_back();
}


void dump(vector<int> &path) {
  for (size_t i = 0; i < path.size(); i++) {
    if (i != 0) printf("->");
    printf("%d", path[i]);
  }
  printf("\n");
}


int main() {
  scanf("%d %d", &N, &M);
  for (size_t i = 0; i < M; i++) {
    int f, t, d;
    scanf("%d %d %d", &f, &t, &d);
    g[f].push_back({ f, t, d });
    deg[t]++;
    nds.insert(f);
    nds.insert(t);
  }

  if (!topsort() || nds.size()) {
    printf("NO %d", nds.size());
    return 0;
  }

  auto maxd = solve();

  for (int i = 0; i < N; i++) {
    if (dp[i] == maxd) {
      dfs(i);
    }
  }

  sort(paths.begin(), paths.end(), [](vector<int> &l, vector<int> &r) {
    return lexicographical_compare(l.begin(), l.end(), r.begin(), r.end());
  });
  printf("YES %d\n", maxd);
  for (auto &p : paths) {
    dump(p);
  }

}
