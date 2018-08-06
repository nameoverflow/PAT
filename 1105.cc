#include <cstdio>
#include <utility>
#include <cmath>
#include <algorithm>
#include <functional>

using namespace std;

pair<int, int> find(int n) {
  int m = sqrt(n);
  int mmin = n;
  int p, d;
  for (int i = n; i >= m; i--) {
    if (n % i == 0) {
      if (mmin > abs(n / i - i)) {
        p = i;
        d = n / i;
        mmin = abs(p - d);
      }
    }
  }
  return make_pair(max(p, d), min(p, d));
}

int g[10010][10010] = {0};
int nn[10010] = {0};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &nn[i]);
  sort(nn, nn + n, greater<int>());
  auto shit = find(n);
  // printf("%d %d\n", shit.first, shit.second);
  int l = 0, r = shit.second, t = 0, d = shit.first;
  int cur = 0;
  while (cur < n) {
    for (int i = l; i < r && cur < n; i++) {
      g[t][i] = nn[cur++];
      // printf("%d %d\n", t, i);
    }
    t++;
    for (int i = t; i < d && cur < n; i++) {
      g[i][r - 1] = nn[cur++];
      // printf("%d %d\n", i, r - 1);
    }
    r--;
    for (int i = r - 1; i >= l && cur < n; i--) {
      g[d - 1][i] = nn[cur++];
      // printf("%d %d\n", d - 1, i);
    }
    d--;
    for (int i = d - 1; i >= t && cur < n; i--) {
      // printf("%d %d\n", i, l);
      g[i][l] = nn[cur++];
    }
    l++;
  }

  for (int i = 0; i < shit.first; i++) {
    printf("%d", g[i][0]);
    for (int j = 1; j < shit.second; j++) {
      printf(" %d", g[i][j]);
    }
    printf("\n");
  }
}
