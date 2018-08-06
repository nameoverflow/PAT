#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;
using ull = unsigned long long;

ull tbl[12000] = {0};
bool prime[12000];
// map<int, int> cor;
// vector<int> res;

void initp() {
  fill(prime, prime + 12000, 1);
  prime[0] = 0;
  prime[1] = 0;
  for (int i = 2; i < 12000; i++) {
    if (!prime[i]) continue;
    for (int j = i << 1; j < 12000; j += i) {
      prime[j] = 0;
    }
  }
}

int main() {
  ull ms, n;
  scanf("%llu %llu", &ms, &n);
  initp();
  while (!prime[ms]) ms++;

  for (ull i = 0; i < n; i++) {
    ull cur;
    scanf("%llu", &cur);
    ull d = 0;
    if (i > 0) printf(" ");
    // printf("%d:%d ", h, tbl[h + (d << 1)]);
    for (; d < ms - 1; d++) {
      ull h = (cur + d * d) % ms;
      if (tbl[h] == 0 || tbl[h] == cur) break;
    }
    if (d >= ms - 1) {
      printf("-");
    } else {
      tbl[(cur + d * d) % ms] = cur;
      printf("%llu", (cur + d * d) % ms);
    }
  }

}
