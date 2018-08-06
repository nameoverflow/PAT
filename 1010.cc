#include <iostream>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

typedef unsigned long long ull;

#define LOG(__t) cout << ""#__t": " << __t << endl

char a[15] = {0}, b[15] = {0};

int to_num(char *src) {
  int len = 0;
  while (src[len]) {
    if (src[len] >= '0' && src[len] <= '9') src[len] -= '0';
    else src[len] = src[len] - 'a' + 10;
    len++;
  }
  return len;
}

ull cvrt(char *src, int len, ull radix) {
  ull res = src[0];
  for (int i = 1; i < len; i++) {
    res *= radix;
    res += src[i];
  }
  return res;
}

ull bs(char *left, char *right, ull lr) {
  int llen = to_num(left);
  int rlen = to_num(right);

  int minr = 0;
  for (int i = 0; i < llen; i++) {
    if (minr < left[i]) minr = left[i];
  }
  minr++;

  ull ldest = cvrt(left, llen, lr);
  ull top = ldest + 1 < 2 ? 2 : ldest + 1;
  ull bottom = 0;
  ull m;
  bool found = false;
  while (bottom <= top) {
    m = (bottom + top) / 2;
    ull rdest = cvrt(right, rlen, m);
    if (rdest < ldest) {
      bottom = m + 1;
    } else if (rdest > ldest) {
      top = m - 1;
    } else {
      found = true;
      break;
    }
  }
  return found ? m : 0;
}

int main() {
  int tag = 0;
  ull rt = 0;
  ull nr = 0, nt = 0;

  scanf("%s %s %d %d", a, b, &tag, &rt);

  ull res;
  if (tag == 1) {
    res = bs(a, b, rt);
  } else {
    res = bs(b, a, rt);
  }

  if (!res) {
    cout << "Impossible" << endl;
  } else {
    cout << res << endl;
  }
}