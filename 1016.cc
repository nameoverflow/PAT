#include <cstdio>
#include <map>
#include <utility>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>

using namespace std;

#define REP(__i, __n) for(size_t __i = 0; __i < __n; __i++)
#define REP1(__i, __n) for(size_t __i = 1; __i < __n; __i++)
#define se second
#define fi first

#define NT (24)

enum rec {
  ON,
  OFF
};

using ET = tuple<int, int, int, rec>;
using ull = unsigned long long;
// pair<int, pair<int, pair<int, rec>>>;

int rates[NT] = {0};
ull span[NT][NT] = {0};
int day = 0;

ull calc(ET &st, ET &ed) {
  ull am = day * (get<0>(ed) - get<0>(st) + 1);
  if (get<1>(st) > 0) am -= span[0][get<1>(st) - 1];
  if (get<2>(st) > 0) am -= rates[get<1>(st)] * get<2>(st);
  if (get<1>(ed) < 23) am -= span[get<1>(ed) + 1][23];
  am -= (60 - get<2>(ed)) * rates[get<1>(ed)];
  return am;
}

int main() {
  int N;
  int m;
  map<string, vector<ET>> bills;
  vector<pair<string, ET>> arc;
  REP(i, NT) {
    scanf("%d", &rates[i]);
    span[i][i] = rates[i] * 60;
    day += span[i][i];
  }
  REP(i, NT) {
    for (int j = i + 1; j < NT; j++) {
      span[i][j] = span[i][j - 1] + rates[j] * 60;
    }

  }
  scanf("%d", &N);

  REP(i, N) {
    char buff[25];
    char tag[10];
    ET en;
    scanf("%s %d:%d:%d:%d %s", buff, &m, &get<0>(en), &get<1>(en), &get<2>(en), tag);
    get<3>(en) = string(tag) == "on-line" ? ON : OFF;
    // bills[buff].push_back(en);
    arc.push_back(make_pair(buff, en));
  }

  sort(arc.begin(), arc.end(), less<pair<string, ET>>());

  REP1(i, N) {
    if (arc[i - 1].fi == arc[i].fi && get<3>(arc[i - 1].se) == ON && get<3>(arc[i].se) == OFF) {
      auto &v = bills[arc[i - 1].fi];
      v.push_back(arc[i - 1].se);
      v.push_back(arc[i].se);
      i++;
    }
  }

  for (auto &v : bills) {
    printf("%s %02d\n", v.fi.c_str(), m);
    // sort(v.se.begin(), v.se.end(), less<ET>());
    bool open = false;
    ET pre;
    ull total = 0;
    REP1(i, v.se.size()) {
      ull len = (get<0>(v.se[i]) - get<0>(v.se[i - 1])) * 24 * 60 + (get<1>(v.se[i]) - get<1>(v.se[i - 1])) * 60 + (get<2>(v.se[i]) - get<2>(v.se[i - 1]));
      ull amount = calc(v.se[i - 1], v.se[i]);
      total += amount;
      printf("%02d:%02d:%02d %02d:%02d:%02d %llu $%.2f\n",
              get<0>(v.se[i - 1]), get<1>(v.se[i - 1]), get<2>(v.se[i - 1]),
              get<0>(v.se[i]), get<1>(v.se[i]), get<2>(v.se[i]),
              len, amount / 100.0);
      i++;
    }
    printf("Total amount: $%.2f\n", total / 100.0);
  }
}