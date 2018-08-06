#include <map>
#include <vector>
#include <string>
#include <cinttypes>
#include <set>
#include <cstdio>
#include <iostream>

using namespace std;
#define LOG(__t) cout << ""#__t": " << __t << endl

#define MP make_pair
#define PI pair<int, T>
#define fi first
#define se second

enum T { M, F };

#define GS(__i) (((ID)__i).s)

map<PI, set<PI>> g;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    PI f, t;
    string s1, s2;
    cin >> s1 >> s2;
    f.fi = abs(stoi(s1));
    f.se = s1[0] == '-' ? F : M;
    t.fi = abs(stoi(s2));
    t.se = s2[0] == '-' ? F : M;
    g[f].insert(t);
    g[t].insert(f);
  }

  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    PI f, t;
    string s1, s2;
    cin >> s1 >> s2;
    f.fi = abs(stoi(s1));
    f.se = s1[0] == '-' ? F : M;
    t.fi = abs(stoi(s2));
    t.se = s2[0] == '-' ? F : M;

    set<pair<int, int>> res;
    if (g.find(f) != g.end() && g.find(t) != g.end()) {
      for (auto n1 : g[f]) {
        if (n1.se != f.se || n1 == t) {
          continue;
        }
        for (auto n2 : g[n1]) {
          if (g[t].find(n2) == g[t].end() || n2 == f)
            continue;
          if (n2.se == t.se) {
            res.insert(make_pair(abs(n1.fi), abs(n2.fi)));
          }
        }
      }
    }
    cout << res.size() << endl;
    if (res.size()) {
      for (auto &p : res) {
        printf("%04d %04d\n", p.fi, p.se);
      }
    }
  }
}