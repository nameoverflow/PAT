#include <cstdio>
#include <set>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

#define ull unsigned long long
#define MP make_pair
#define PI pair<int, int>
#define TI tuple<int, int, int>
#define MT make_tuple

#define NMAX (10010)
#define LOG(__t) cout << ""#__t": " << __t << endl

vector<PI> g[NMAX];
int N;

int f[NMAX];
int find(int l) {
  int cur = l;
  while (cur != f[cur]) {
    cur = f[l] = f[cur];
  }
  return cur;
}

void join(int x, int y) {
  f[find(x)] = find(y);
}

int maxd = 0;
// set<int> maxn;
void dfs(int pre, int st, int d, set<int> &maxn) {
  if (g[st].size() == 1 && g[st][0].second == pre) {
    if (d > maxd) {
      maxd = d;
      maxn = {st};
    } else if (d == maxd) {
      maxn.insert(st);
    }
    return;
  }
  for (auto &e : g[st]) {
    if (e.second == pre) continue;
    dfs(st, e.second, d + 1, maxn);
  }
}

int main() {
  int span = 0;
  scanf("%d", &N);
  for (int i = 1; i < N + 1; i++) {
    f[i] = i;
  }
  for (int i = 1; i < N; i++) {
    int s, t;
    scanf("%d %d", &s, &t);
    g[s].push_back(MP(s, t));
    g[t].push_back(MP(t, s));
    if (find(s) != find(t)) {
      span++;
      join(s, t);
    }
  }
  if (span < N - 1) {
    printf("Error: %d components", N - span);
    return 0;
  }
  set<int> s1;
  maxd = 0;
  dfs(0, 1, 0, s1);
  maxd = 0;
  set<int> s2;
  dfs(0, *s1.begin(), 0, s2);

  for (auto &e : s1) {
    s2.insert(e);
  }

  if (N == 1) printf("1");
  for (auto &e : s2) {
    printf("%d\n", e);
  }

}
