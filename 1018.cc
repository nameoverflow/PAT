#include <cstdio>
#include <utility>
#include <queue>
#include <functional>
#include <tuple>
#include <stack>
#include <limits>
#include <set>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;
#define LOG(__t) cout << ""#__t": " << __t << endl

#define fi(__d) get<0>(__d)
#define se(__d) get<1>(__d)
#define th(__d) get<2>(__d)
#define ull unsigned long long
#define ll long long
#define PLL pair<ull, ull>
#define MP make_pair
#define MT make_tuple

#define NMAX (550)

using E = tuple<ull, ull, ull>;

vector<E> g[NMAX];
ull dist[NMAX];
vector<ull> path[NMAX];
ll s[NMAX] = {0};
ull c, n, sp, m;

void dijk(ull st) {
  fill(dist + 1, dist + n + 1, ULLONG_MAX - 10);
  priority_queue<E, vector<E>, greater<E>> pq;
  dist[st] = 0;
  for (auto &e : g[st]) {
    pq.push(e);
  }

  while (pq.size()) {
    auto ce = pq.top(); pq.pop();
    if (dist[se(ce)] + fi(ce) < dist[th(ce)]) {
      dist[th(ce)] = dist[se(ce)] + fi(ce);
      path[th(ce)] = { se(ce) };
      for (auto &e : g[th(ce)]) {
        pq.push(e);
      }
    } else if (dist[se(ce)] + fi(ce) == dist[th(ce)]) {
      path[th(ce)].push_back(se(ce));
    }
  }
}

pair<ll, ll> dfs(ull st, vector<ull> &minp) {
  ll bestn = LLONG_MAX - 10;
  ll bestt = LLONG_MAX - 10;
  stack<pair<ull, ull>> sk;
  vector<ull> ps;

  sk.push(MP(st, 1));
  while (sk.size()) {
    auto cv = sk.top(); sk.pop();
    ps.push_back(cv.first);
    if (path[cv.first].empty()) {
      ll need = 0;
      ll take = 0;
      for (int i = ps.size() - 1; i >= 0; i--) {
        ll &cur = s[ps[i]];
        if (cur < 0) {
          if (take >= -cur) {
            take += cur;
          } else {
            need += -cur - take;
            take = 0;
          }
        } else {
          take += cur;
        }
      }
      // LOG(ba);
      if (need < bestn || need == bestn && take < bestt) {
        bestn = need;
        bestt = take;
        minp = ps;
      }
      while (sk.size() && ps.size() + 1 != sk.top().second) ps.pop_back();
      continue;
    }
    for (auto &ch : path[cv.first]) {
      sk.push(MP(ch, cv.second + 1));
    }
  }
  return MP(bestn, bestt);
}

int main() {
  scanf("%llu %llu %llu %llu", &c, &n, &sp, &m);
  for (size_t i = 1; i < n + 1; i++) {
    scanf("%llu", &s[i]);
    s[i] -= c / 2;
  }
  for (size_t i = 0; i < m; i++) {
    ull si, sj, tij;
    scanf("%llu %llu %llu", &si, &sj, &tij);
    g[si].push_back(MT(tij, si, sj));
    g[sj].push_back(MT(tij, sj, si));
  }

  vector<ull> r;
  dijk(0);
  auto total = dfs(sp, r);

  printf("%lld", total.first);

  printf(" 0");
  r.pop_back();
  reverse(r.begin(), r.end());
  for (auto &v : r) {
    printf("->%llu", v);
  }
  printf(" %lld", total.second);
}
