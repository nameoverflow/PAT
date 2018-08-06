#include <iostream>
#include <string>
#include <cstdio>
#include <utility>
#include <functional>
#include <vector>

using namespace std;

#define ll long long
#define LOG(__t) cout << ""#__t": " << __t << endl
#define pll pair<ll, ll>
#define MP make_pair

pll tbl[100010];

vector<pll> v[3];
int main() {
  ll n, k, st;
  scanf("%lld %lld %lld", &st, &n, &k);

  for (size_t i = 0; i < n; i++) {
    ll ad, dt, nt;
    scanf("%lld %lld %lld", &ad, &dt, &nt);
    tbl[ad] = make_pair(dt, nt);
  }

  ll p = st;
  while (p != -1) {
    pll fuck = MP(p, tbl[p].first);
    if (tbl[p].first < 0) {
      v[0].push_back(fuck);
    } else if (tbl[p].first <= k) {
      v[1].push_back(fuck);
    } else {
      v[2].push_back(fuck);
    }
    p = tbl[p].second;
  }
  bool open = false;
  if (v[0].size()) {
    for (ll i = 0; i < v[0].size() - 1; i++) {
      printf("%05lld %lld %05lld\n", v[0][i].first, v[0][i].second, v[0][i + 1].first);
    }
    printf("%05lld %lld ", v[0][v[0].size() - 1].first, v[0][v[0].size() - 1].second);
    open = true;
  }
  if (v[1].size()) {
    if (open) printf("%05lld\n", v[1][0].first);
    open = false;
    for (ll i = 0; i < v[1].size() - 1; i++) {
      printf("%05lld %lld %05lld\n", v[1][i].first, v[1][i].second, v[1][i + 1].first);
    }
    printf("%05lld %lld ", v[1][v[1].size() - 1].first, v[1][v[1].size() - 1].second);
    open = true;
  }
  if (v[2].size()) {
    if (open) printf("%05lld\n", v[2][0].first);
    open = false;
    for (ll i = 0; i < v[2].size() - 1; i++) {
      printf("%05lld %lld %05lld\n", v[2][i].first, v[2][i].second, v[2][i + 1].first);
    }
    printf("%05lld %lld ", v[2][v[2].size() - 1].first, v[2][v[2].size() - 1].second);
    open = true;
  }
  if (open) printf("-1");
}
