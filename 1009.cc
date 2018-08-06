#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

#define LOG(__t) cout << ""#__t": " << __t << endl

typedef long long ll;

int main() {
  map<int, double> p1, p2;
  int num;

  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    int e; double c;
    scanf("%d %lf", &e, &c);
    p1[e] = c;
  }

  scanf("%d", &num);
  for (int i = 0; i < num; i++) {
    int e; double c;
    scanf("%d %lf", &e, &c);
    p2[e] = c;
  }

  map<int, double> res;

  for (auto &v1 : p1) {
    for (auto &v2 : p2) {
      int e = v1.first + v2.first;
      double c = v1.second * v2.second;
      res[e] += c;
    }
  }
  for (auto &v : res) {
    if (v.second == 0) {
      res.erase(v.first);
    }
  }

  vector<pair<int, double>> resv(res.begin(), res.end());
  reverse(resv.begin(), resv.end());

  printf("%d", res.size());
  for (auto &v : resv) {
    printf(" %d %.1lf", v.first, v.second);
  }
}
