#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long ull;

#define LOG(__t) std::cout << ""#__t": " << __t << std::endl

char L[220] = {0} , R[220] = {0};
char ldig[220] = {0}, rdig[220] = {0};

int get_sign(char *src, char *dest, int sig) {
  int len = 0;
  int fac = 0;
  int pt = 233;
  bool zero = true;
  while (src[len] && src[len] == '0') len++;
  if (src[len] == '.') {
    pt = 0; len++;
  }
  while (src[len] && src[len] == '0') {
    pt--;
    len++;
  }
  for (fac = 0; src[len] && fac < sig; len++, fac++) {
    if (src[len] == '.') {
      pt = fac;
      fac--;
      continue;
    }
    dest[fac] = src[len];
    if (src[len] != '0') zero = false;
  }
  if (!src[len]) {
    while (fac < sig) {
      dest[fac] = '0';
      fac++;
    }
  } else while (src[len]) {
    if (src[len] == '.') {
      pt = len;
    }
    len++;
  }
  if (zero) pt = 0;
  if(pt == 233) pt = len;
  if (!fac) dest[0] = '0';
  return pt;
}

int main() {
  int sig = 0;
  scanf("%d %s %s", &sig, L, R);

  int facl, facr, llen = 0, rlen = 0, lp = -1, rp = -1;

  lp = get_sign(L, ldig, sig);
  rp = get_sign(R, rdig, sig);

  bool ineq = false;
  if (lp != rp) ineq = true;
  else for (int i = 0; i < sig; i++) {
    if (ldig[i] != rdig[i]) {
      ineq = true;
      break;
    }
  }

  if (ineq) {
    printf("NO 0.%s*10^%d 0.%s*10^%d", ldig, lp, rdig, rp);
  } else {
    printf("YES 0.%s*10^%d", ldig, lp);
  }
}