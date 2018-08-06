#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

using P = pair<int, int>;
using PP = pair<int, P>;
#define MP make_pair


PP lst[100110];
int main() {
  int n, st;
  set<PP, less<PP>> nd;
  scanf("%d%d", &n, &st);
  for (int i = 0; i < n; i++) {
    int a, c, n;
    scanf("%d%d%d", &a, &c, &n);
    lst[a].first = c;
    lst[a].second.first = a;
    lst[a].second.second = n;
  }

  for (int aa = st; aa != -1; aa = lst[aa].second.second) {
    nd.insert(lst[aa]);
  }
  if (nd.empty() || st == -1) {
    printf("0 -1");
    return 0;
  }

  printf("%d %05d\n%05d %d", nd.size(), (*nd.begin()).second.first, (*nd.begin()).second.first, (*nd.begin()).first);
  // for (int i = 0; i < n - 1; i++) {
  //   printf("%05d %d %05d\n", lst[i].second, lst[i].first, lst[i + 1].second);
  // }
  // printf("%05d %d %d", lst[n - 1].second, lst[n - 1].first, -1);
  auto it = nd.begin();
  it++;
  for (; it != nd.end(); it++) {
    printf(" %05d\n%05d %d", (*it).second.first, (*it).second.first, (*it).first);
  }
  printf(" -1");
}

