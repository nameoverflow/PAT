#include <cstdio>
#include <map>

using namespace std;

using ull = unsigned long long;
using P = pair<ull, ull>;

#define MP make_pair
#define NMAX (1010)

ull f[NMAX];
P e[NMAX * NMAX];

ull find(ull l) {
  ull cur = l;
  while (cur != f[cur]) {
    cur = f[l] = f[cur];
  }
  return cur;
}

void join(ull x, ull y) {
  f[x] = y;
}

ull mst(ull ext, ull n, ull m) {
  ull count = 0;
  for (size_t i = 0; i < n + 1; i++) {
    f[i] = i;
  }
  for (size_t i = 0; i < m; i++) {
    if (e[i].first == ext || e[i].second == ext) continue;
    auto x = find(e[i].first);
    auto y = find(e[i].second);
    if (x != y) {
      join(x, y);
      count ++;
    }
  }
  return count;
}

int main() {
  ull N, M, K;
  scanf("%llu %llu %llu", &N, &M, &K);
  for (size_t i = 0; i < M; i++) {
    scanf("%llu %llu", &e[i].first, &e[i].second);
  }
  for (size_t i = 0; i < K; i++) {
    ull cur;
    scanf("%llu", &cur);
    ull ext = mst(cur, N, M);
    printf("%llu\n", N - 2 - ext);
  }
}