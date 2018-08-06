#include <cstdio>
#include <queue>
#include <utility>
#include <tuple>
#include <functional>

using namespace std;
#define REP(__i, __n) for(size_t __i = 0; __i < __n; __i++)
#define REP1(__i, __n) for(size_t __i = 1; __i < __n; __i++)
#define se second
#define fi first

using ull = unsigned long long;
using T = tuple<short, short, short>;
using C = pair<T, short>;

void operator+=(T &l, T &r) {
  get<0>(l) += get<0>(r);
  get<1>(l) += get<1>(r);
  get<2>(l) += get<2>(r);
  if (get<2>(l) > 59) {
    get<2>(l) -= 60;
    get<1>(l)++;
  }
  if (get<1>(l) > 59) {
    get<1>(l) -= 60;
    get<0>(l)++;
  }
}

T operator+(T &l, T &r) {
  T res = l;
  res += r;
  return res;
}

double operator-(T &l, T &r) {
  return (get<0>(l) - get<0>(r)) * 60.0 + (get<1>(l) - get<1>(r)) + (get<2>(l) - get<2>(r)) / 60.0;
}

int main() {
  int n, k;

  scanf("%d %d", &n, &k);

  priority_queue<C, vector<C>, greater<C>> cus;
  priority_queue<T, vector<T>, greater<T>> win;

  REP(i, n) {
    C c;
    scanf("%hd:%hd:%hd %hd", &get<0>(c.fi), &get<1>(c.fi), &get<2>(c.fi), &c.se);
    cus.push(c);
  }

  REP(i, k) {
    win.push(make_tuple(8,0,0));
  }
  double total = 0;
  int count = 0;
  while (cus.size()) {
    auto cur = cus.top(); cus.pop();
    if (cur.fi > make_tuple(17, 0, 0)) {
      break;
    }
    count ++;
    auto w = win.top(); win.pop();
    if (w > cur.fi) {
      total += w - cur.fi;
    }
    T add = make_tuple(0, cur.se, 0);
    add += cur.fi > w ? cur.fi : w;
    win.push(add);
  }
  printf("%.1lf", total / count);
}
