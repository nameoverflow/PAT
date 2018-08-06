#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define LOG(__t) cout << ""#__t": " << __t << endl

int main() {
  int total = 0;
  map<int, double> p1;


  scanf("%d", &total);
  for (int i = 0; i < total;) {
    int ex;
    double co;
    scanf("%d %lf", &ex, &co);
    if (co != 0) {
      p1[ex] = co;
      i++;
    }
  }
  scanf("%d", &total);
  for (int i = 0; i < total;) {
    int ex;
    double co;
    scanf("%d %lf", &ex, &co);
    if (co != 0) {
      p1[ex] = p1[ex] + co;
       i++;
    }
  }

  for (auto &v : p1) {
    if (v.second == 0) {
      p1.erase(v.first);
    }
  }

  printf("%d", p1.size());
  vector<pair<int, double>> r(p1.begin(), p1.end());
  reverse(r.begin(), r.end());
  for (auto &v : r) {
    printf(" %d %.1f", v.first, v.second);
  }
}
