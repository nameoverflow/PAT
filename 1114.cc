#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_set>
#include <utility>
#include <stack>
#include <algorithm>
#include <tuple>

using namespace std;

#define PII pair<int, int>

map<int, unordered_set<int>> fa;
map<int, PII> es;
// map<int, PII> pa;
unordered_set<int> all;

int id = 10000, mem = 0, ts = 0, ta = 0;
unordered_set<int> vis;
void dfs(int nn) {
  if (nn < 0) return;
  if (vis.find(nn) != vis.end()) return;
  // printf("%d %d %d %d\n", mem, nn, es[nn].first, es[nn].second);
  mem++;
  vis.insert(nn);
  all.erase(nn);
  id = min(id, nn);
  ts += es[nn].first;
  ta += es[nn].second;
  for (auto nxt : fa[nn]) {
    dfs(nxt);
  }
  // vis.erase(nn);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int n, f, m, c, en, ea;
    scanf("%d %d %d %d", &n, &f, &m, &c);
    all.insert(n);
    fa[n].insert(f);
    fa[n].insert(m);
    fa[f].insert(n);
    fa[m].insert(n);
    for (int j = 0; j < c; j++) {
      int cc;
      scanf("%d", &cc);
      fa[n].insert(cc);
      fa[cc].insert(n);
    }
    scanf("%d %d", &en, &ea);
    es[n].first = en;
    es[n].second += ea;
  }
  // for (auto v : all) {
  //   printf("%d\n", v);
  // }
  vector<tuple<int, int, double, double>> res;
  while (all.size()) {
    id = 10000;
    mem = 0;
    ts = 0;
    ta = 0;
    vis.clear();
    auto t = *all.begin();
    dfs(t);
    all.erase(t);
    res.push_back(make_tuple(id, mem, (double)ts / mem, (double)ta / mem));
  }
  sort(res.begin(), res.end(), [](tuple<int, int, double, double> &l, tuple<int, int, double, double> &r) {
    return get<3>(l) > get<3>(r) || (get<3>(l) == get<3>(r) && get<0>(l) < get<0>(r));
  });

  printf("%d\n", res.size());
  for (auto &v : res) {
    printf("%04d %d %.3lf %.3lf\n", get<0>(v), get<1>(v), get<2>(v), get<3>(v));
  }
}
