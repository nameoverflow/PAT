#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

#define REP(__i, __n) for(int __i = 0; __i < __n; __i++)
int f[10010] = {0};

int find(int x) {
  for (int cur = x;; cur = f[x] = f[cur])
    if (f[cur] == cur) return cur;
}

int join(int x, int y) {
  f[find(x)] = find(y);
}

int main() {
  int n, k;
  int bd = 0, ed = 0;
  scanf("%d", &n);
  REP(i, 10009) {
    f[i] = i;
  }
  REP(_, n) {
    scanf("%d", &k);
    int fi;
    scanf("%d", &fi);
    bd = max(bd, fi);
    REP(i, k - 1) {
      int x;
      scanf("%d", &x);
      if (find(fi) != find(x)) {
        join(fi, x);
        ed++;
      }
      bd = max(bd, x);
    }
  }


  printf("%d %d\n", bd - ed, bd);
  scanf("%d", &k);
  while (k--) {
    int x, y;
    scanf("%d %d", &x, &y);
    puts(find(x) == find(y) ? "Yes" : "No");
  }
}
