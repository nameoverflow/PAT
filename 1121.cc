#include <map>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int main() {
  map<long, long> cp;
  set<long> sg;

  long n;
  scanf("%ld", &n);
  for (long i = 0; i < n; i++) {
    long cp1, cp2;
    scanf("%ld %ld", &cp1, &cp2);
    cp[cp1] = cp2;
    cp[cp2] = cp1;
  }

  scanf("%ld", &n);
  for (long i = 0; i < n; i++) {
    long l;
    scanf("%ld", &l);
    if (cp.find(l) != cp.end() && sg.find(cp[l]) != sg.end()) {
      sg.erase(l);
      sg.erase(cp[l]);
    } else {
      sg.insert(l);
    }
  }
  printf("%d\n", sg.size());
  bool flag = 0;
  for (auto v : sg) {
    if (!flag) {
      printf("%05ld", v);
      flag = true;
    } else 
    printf(" %05ld", v);
  }
}
