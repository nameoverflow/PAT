#include <cstdio>
#include <set>

using namespace std;

set<int> g[1010];

int f[1010];

int find(int x) {
  while ((x = f[x]) != f[x]);
  return x;
}

int join(int x, int y) {
  f[find(x)] = f[find(y)];
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  int count = 0;
  for (int i = 1; i < n + 1; i++) {
    f[i] = i;
  }
  for (int i = 0; i < m; i++) {
    int f, t;
    scanf("%d %d", &f, &t);
    if (find(f) != find(t)) {
      join(f, t);
      count ++;
    }
    g[f].insert(t);
    g[t].insert(f);
  }

  int e = g[1].size() % 2 == 0, o = !e;
  printf("%d", g[1].size());
  for (int i = 2; i < n + 1; i++) {
    printf(" %d", g[i].size());
    if (g[i].size() != 0) {
      if (g[i].size() % 2 == 0) {
        e++;
      } else {
        o++;
      }
    }
  }
  if (e == n && count == n - 1) {
    printf("\nEulerian");
  } else if (o == 2 && count == n - 1) {
    printf("\nSemi-Eulerian");
  } else {
    printf("\nNon-Eulerian");
  }
}
