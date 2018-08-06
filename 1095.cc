#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <unordered_set>
#include <functional>
#include <queue>
#include <unordered_map>
#include <iostream>

using namespace std;

#define LOG(__t) cout << #__t": " << __t << endl;

#define ull unsigned long long
#define MT make_tuple
#define MP make_pair
#define fi(d) get<0>(d)
#define se(d) get<1>(d)
#define th(d) get<2>(d)

union Plate {
  char s[8];
  ull h;
};

enum St {
  IN,
  OUT
};

// using TT = tuple<int, int, int>;
using TTP = tuple<int, ull, St>;
using PIU = pair<int, ull>;

int main() {
  ull n, k;
  scanf("%llu %llu", &n, &k);
  vector<TTP> all;
  all.reserve(n);
  for (ull i = 0; i < n; i++) {
    TTP c;
    Plate p;
    char sts[10];
    int h, m, s;
    scanf("%s %d:%d:%d %s", p.s, &h, &m, &s, sts);
    fi(c) = h * 3600 + m * 60 + s;
    se(c) = p.h;
    if (string(sts) == "in") {
      th(c) = IN;
    } else {
      th(c) = OUT;
    }
    all.push_back(c);
  }
  sort(all.begin(), all.end(), greater<TTP>());
  
  // vector<TTP> res_in;
  // unordered_set<ull> in;
  // for (auto &cur : all) {
  //   //     {
  //   //   Plate pp;
  //   //   pp.h = se(cur);
  //   //   int h = fi(cur) / 3600;
  //   //   int m = (fi(cur) % 3600) / 60;
  //   //   int s = (fi(cur) % 60);
  //   //   printf("%s %d:%d:%d %s\n", pp.s, h, m, s, th(cur) == IN ? "in" : "out");
  //   // }
  //   if (th(cur) == IN) {
  //     in.insert(se(cur));
  //     res_in.push_back(cur);
  //   } else if (in.find(se(cur)) != in.end()) {
  //     res_in.push_back(cur);
  //     in.erase(se(cur));
  //   }
  // }
  // // for (auto &cur : res_in) {
  // //       {
  // //     Plate pp;
  // //     pp.h = se(cur);
  // //     int h = fi(cur) / 3600;
  // //     int m = (fi(cur) % 3600) / 60;
  // //     int s = (fi(cur) % 60);
  // //     printf("%s %d:%d:%d %s\n", pp.s, h, m, s, th(cur) == IN ? "in" : "out");
  // //   }
  // // }

  vector<TTP> res;
  unordered_map<ull, int> out;
  res.reserve(n);
  unordered_map<ull, int> stay;
  int maxs = 0;
  vector<ull> maxc;
  for (auto &cur : all) {
  // for (long long i = res_in.size() - 1; i >= 0; i--) {
  //   auto &cur = res_in[i];
    if (th(cur) == OUT) {
      out[se(cur)] = fi(cur);
      res.push_back(cur);
    } else if (out.find(se(cur)) != out.end()) {
      res.push_back(cur);
      stay[se(cur)] += out[se(cur)] - fi(cur);
      if (stay[se(cur)] > maxs) {
        maxs = stay[se(cur)];
        maxc.clear();
      }
      if (stay[se(cur)] == maxs) {
        maxc.push_back(se(cur));
      }

      out.erase(se(cur));
    }
  }
  // for (auto &cur : res) {
  //       {
  //     Plate pp;
  //     pp.h = se(cur);
  //     int h = fi(cur) / 3600;
  //     int m = (fi(cur) % 3600) / 60;
  //     int s = (fi(cur) % 60);
  //     printf("%s %d:%d:%d %s\n", pp.s, h, m, s, th(cur) == IN ? "in" : "out");
  //   }
  // }

  unordered_set<ull> cc;
  for (ull i = 0, j = res.size() - 1; i < k; i++) {
    int h, m, s;
    scanf("%d:%d:%d", &h, &m, &s);
    int ti = h * 3600 + m * 60 + s;
    while (fi(res[j]) <= ti) {
      if (th(res[j]) == IN) {
        cc.insert(se(res[j]));
      } else {
        cc.erase(se(res[j]));
      }
      j--;
    }
    printf("%d\n", cc.size());
  }

  sort(maxc.begin(), maxc.end(), greater<ull>());
  Plate pp;
  for (auto &c : maxc) {
    pp.h = c;
    printf("%s ", pp.s);
  }
  int h = maxs / 3600;
  int m = (maxs % 3600) / 60;
  int s = (maxs % 60);
  printf("%02d:%02d:%02d", h, m, s);
}
