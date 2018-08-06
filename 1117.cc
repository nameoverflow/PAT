#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

int main() {
  int n;
  scanf("%d", &n);

  map<int, int> counts;
  for (int i = 0; i < n; i++) {
    int d;
    scanf("%d", &d);
    counts[d]++;
  }

  vector<pair<int, int>> v(counts.rbegin(), counts.rend());
  // for (auto &d : v) {
  //   printf("%d %d\n", d.first, d.second);
  // }

  int cc = 0;
  for (auto &d : v) {
    // printf("%d %d\n", d.first, cc);
    if (cc > d.first) {
      printf("%d", d.first);
      break;
    } 
    cc += d.second;
    // printf("- %d %d\n", d.first, cc);
    if (cc >= d.first - 1) {
      printf("%d", d.first - 1);
      break;
    }
  }
}
