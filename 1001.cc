#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main () {
  ll left, right;
  scanf("%lld %lld", &left, &right);
  string s = to_string(left + right);
  const char *dest = s.c_str();

  int len = s.length();
  if (dest[0] == '-') {
    putchar('-');
    dest += 1;
    len--;
  }
  for (int i = len; i > 0; i--) {
    int cur = len - i;
    putchar(dest[cur]);
    if ((i - 1) && (i - 1) % 3 == 0) putchar(',');
  }
}

