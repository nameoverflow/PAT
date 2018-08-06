#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int n;
  cin >> n;

  for (int l = 12; l >= 1; l--) {
    for (int s = 2; s <= sqrt(n); s++) {
      unsigned long long r = 1;
      for (int i = 0; i < l; i++) {
        r *= s + i;
      }
      if (n % r == 0) {
        printf("%d\n", l);
        for (int i = 0; i < l; i++) {
          if (i > 0) printf("*");
          printf("%d", s + i);
        }
        goto ee;
      }
    }
  }
  printf("1\n%d", n);
ee:
  return 0;
}
