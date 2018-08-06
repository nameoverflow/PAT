#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

using P = pair<int, int>;
#define MP make_pair
#define fi first
#define se second

int lv[100];
vector<int> fam[110];

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    int p, cn;
    scanf("%d %d", &p, &cn);
    for (int j = 0; j < cn; j++) {
      int ch;
      scanf("%d", &ch);
      fam[p].push_back(ch);
    }
  }

  queue<P> q;
  q.push(MP(1, 1));

  int maxlv = 0, maxc = 0;

  while (q.size()) {
    auto cur = q.front().fi, clv = q.front().se;
    q.pop();

    for (auto ch : fam[cur]) {
      q.push(MP(ch, clv + 1));
    }

    lv[clv]++;
    if (lv[clv] > maxc) {
      maxlv = clv;
      maxc = lv[clv];
    }
  }
  printf("%d %d", maxc, maxlv);
}
