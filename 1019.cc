#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

using ull = unsigned long long;

using namespace std;

int main () {
  ull n, b;
  scanf("%llu %llu", &n, &b);

  if (n == 0) {
    printf("Yes\n0");
    return 0;
  }

  vector<ull> res;
  while (n > 0) {
    res.push_back(n % b);
    n /= b;
  }

  bool f = true;
  for (size_t i = 0; i < res.size() / 2; i++) {
    f = res[i] == res[res.size() - 1 - i];
    if (!f) break;
  }

  printf(f ? "Yes\n" : "No\n");

  reverse(res.begin(), res.end());
  printf("%llu", res[0]);
  for (size_t i = 1; i < res.size(); i++) {
    printf(" %llu", res[i]);
  }
}
