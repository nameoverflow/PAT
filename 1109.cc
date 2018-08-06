#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <utility>
#include <string>
#include <functional>

using namespace std;

using PIS = pair<int, string>;
#define MP make_pair
#define fi first
#define se second

template<typename _It>
deque<PIS> que_row(_It first, _It last, int sz) {
  deque<PIS> row;
  // int mid = (int)floor((float)sz / 2) + 1;
  // printf("%d\n", mid);
  bool rev = false;
  for (; last != first; last--) {
    auto &cur = *(last - 1);
    // printf("%s %d\n", cur.se.c_str(), cur.fi);
    if (rev) row.push_front(cur);
    else row.push_back(cur);
    rev = !rev;
  }
  return row;
}

char buff[100];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int m = floor((float)n / k);
  // int tallest = (int)floor((float)m / 2) + 1;

  vector<PIS> stu;
  stu.reserve(n);
  for (int i = 0; i < n; i++) {
    int t;
    scanf("%s %d", buff, &t);
    stu.push_back(MP(t, string(buff)));
  }

  sort(stu.begin(), stu.end(), [](PIS &l, PIS &r) {
    return l.fi < r.fi || (l.fi == r.fi && l.se > r.se);
  });

  int row = 0;
  vector<deque<PIS>> all;
  all.reserve(k);
  for (; row < k - 1; row++) {
    auto bg = stu.begin() + row * m;
    auto ed = bg + m;
    all.push_back(que_row(bg, ed, m));
  }
  all.push_back(que_row(stu.begin() + row * m, stu.end(), stu.size() - (k - 1) * m));
  for (auto it = all.rbegin(); it != all.rend(); it++) {
    auto &qr = *it;
    printf("%s", qr.front().se.c_str());
    qr.pop_front();
    for (auto &v : qr) {
      printf(" %s", v.se.c_str());
    }
    printf("\n");
  }
}