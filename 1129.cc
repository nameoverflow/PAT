#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;

#define PII pair<long, long>
#define MP make_pair
#define fi first
#define se second

long q[50010] = { 0 };

void update(long cu, long k, vector<PII> &r) {
  q[cu]++;
  long m = 0;
  bool flag = false;
  for (long i = 0; i < r.size(); i++) {
    auto &v = r[i];
    flag = flag || v.se == cu;
    v.fi = q[v.se];
    if (v.fi < r[m].fi || (r[m].fi == v.fi && v.se > r[m].se)) m = i;
  }
  if (!flag) {
    if (r.size() < k) {
      r.push_back(MP(q[cu], cu));
    } else if (r[m].fi < q[cu] || (r[m].fi == q[cu] && r[m].se > cu)) {
      r[m] = MP(q[cu], cu);
    }
  }
  sort(r.begin(), r.end(), [](PII l, PII r) {
    return l.fi > r.fi || (l.fi == r.fi && l.se < r.se);
  });
}

int main() {
  long n, k;
  scanf("%ld %ld", &n, &k);

  vector<PII> r;
  r.reserve(k);
  long nn;
  scanf("%ld", &nn);
  update(nn, k, r);
  for (size_t i = 1; i < n; i++) {
    scanf("%ld", &nn);
    printf("%ld:", nn);
    for (auto &v : r) {
      printf(" %ld", v.se);
    }
    update(nn, k, r);
    printf("\n");
  }
}
