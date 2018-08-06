#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

int main() {
  priority_queue<double, vector<double>, greater<double>> fuck;

  int n;
  scanf("%d", &n);

  int m = 0;
  for (size_t i = 0; i < n; i++) {
    int f;
    scanf("%d", &f);
    m = max(m, f);
    fuck.push((double)f);
  }

  while (fuck.size() > 1) {
    auto shit = fuck.top(); fuck.pop();
    shit += fuck.top();
    shit /= 2;
    fuck.pop();
    fuck.push(shit);
  }
  auto shit = fuck.top();

  int res = min(m, (int)shit);
  // res = max(10000)
  printf("%d", res);
}
