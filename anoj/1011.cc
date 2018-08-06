#include <cstdio>
#include <vector>
#include <set>

using namespace std;

vector<int> g[1010];
int d[1010] = {0};

int main() {
  int m, n;
  set<int> bg;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    int f, t;
    scanf("%d %d", &f, &t);
    g[f].push_back(t);
    d[t]++;
  }

  for (int i = 0; i < n; i++) {
    if (d[i] == 0) bg.insert(i);
  }

  vector<int> res;
  while (bg.size()) {
    int cur = *bg.begin();
    res.push_back(cur);
    bg.erase(cur);
    for (auto v : g[cur]) {
      d[v]--;
      if (d[v] == 0) bg.insert(v);
    }
  }

  if (n == res.size()) {
    printf("YES\n");
    printf("%d", res[0]);
    for (int i = 1; i < res.size(); i++) {
      printf(" %d", res[i]);
    }
  } else {
    printf("NO\n%d", n - res.size());
  }
}
