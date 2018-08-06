#include <string>
#include <cstdio>
#include <cmath>

#include <iostream>

using namespace std;
#define LOG(__t) cout << ""#__t": " << __t << endl

char buf[100010] = {0};

int itoa_r(int src, int radix, char *buffer) {
  int len = 0;
  for (len = 0; src > 0; src /= radix, len++) {
    buffer[len] = src % radix;
  }
  return len;
}

int r_atoi(char *src, int len, int radix) {
  int res = 0;
  for (int i = 0; i < len; i++) {
    res *= radix;
    res += src[i];
  }
  return res;
}

bool prim(int n) {
  if (n < 2) return false;
  int t = sqrt(n) + 1;
  bool res = true;
  for (int i = 2; i < t; i++) {
    if (n % i == 0) res = false;
  }
  return res;
}

int main () {
  int n, d;
  while (scanf("%d", &n) && n >= 0) {
    scanf("%d", &d);
    if (prim(n) && prim(r_atoi(buf, itoa_r(n, d, buf), d))) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
}
