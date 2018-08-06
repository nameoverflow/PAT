#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>

using namespace std;
// using U = pair<int, int>;
using U = tuple<int, int, int>;

int pr[10010][5];
int ps[5];
bool av[10010] = {0};

int main() {
  int n, k, m;
  scanf("%d %d %d", &n, &k, &m);
  for (int i = 0; i < k; i++) {
    scanf("%d", &ps[i]);
  }
  memset(pr, 0xff, sizeof(pr));
  for (int i = 0; i < m; i++) {
    int id, p, s;
    scanf("%d %d %d", &id, &p, &s);
    if (s > -1) av[id] = 1;
    s = s == -1 ? 0 : s;
    
    pr[id][p - 1] = max(pr[id][p - 1], s);
  }

  vector<U> rk;
  rk.reserve(n);
  for (int i = 1; i < n + 1; i++) {
    int sc = 0;
    int pf = 0;
    if (!av[i]) continue;
    for (int j = 0; j < k; j++) {
      if (pr[i][j] != -1) {
        sc += pr[i][j];
      }
      if (pr[i][j] == ps[j]) pf++;
    }
    rk.push_back(make_tuple(sc, pf, -i));
  }
  sort(rk.begin(), rk.end(), greater<U>());
  int pre = 0;
  for (int r = 0, o = 0; r < rk.size(); r++) {
    auto id = -get<2>(rk[r]);
    auto sc = get<0>(rk[r]);
    if (sc != pre) {
      o = r + 1;
    }
    pre = sc;
    // if (sc == 0) break;
    printf("%d %05d %d", o, id, sc);
    for (int i = 0; i < k; i++) {
      if (pr[id][i] < 0) printf(" -");
      else printf(" %d", pr[id][i]);
    }
    printf("\n");
  }
}
