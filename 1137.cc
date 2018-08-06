#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;


struct G {
  short p = -1, m = -1, f = -1;
};

unordered_map<string, G> s;

int main() {
  int p, m, n;
  scanf("%d %d %d", &p, &m, &n);
  char buf[20];
  for (int i = 0; i < p; i++) {
    scanf("%s", buf);
    scanf("%hd", &s[buf].p);
  }
  for (int i = 0; i < m; i++) {
    scanf("%s", buf);
    scanf("%hd", &s[buf].m);
  }
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    scanf("%hd", &s[buf].f);
  }

  vector<pair<short, string>> cert;
  cert.reserve(s.size());

  for (auto &pp : s) {
    auto &stu = pp.second;
    if (stu.p < 200) continue;
    short g;
    if (stu.f > stu.m) {
      g = stu.f;
    } else {
      g = (short)(stu.m * 0.4 + stu.f * 0.6 + 0.49);
    }
    if (g >= 60) {
      cert.push_back(make_pair(g, pp.first));
    }
  }

  sort(cert.begin(), cert.end(), [](pair<short, string> &l, pair<short, string> &r) {
    return l.first > r.first || (l.first == r.first && l.second < r.second);
  });

  for (auto &v : cert) {
    printf("%s %d %d %d %d\n", v.second.c_str(), s[v.second].p, s[v.second].m, s[v.second].f, v.first);
  }
}
