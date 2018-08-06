#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <string>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

struct P {
  string n;
  int a, w;
};

P pp[100010];

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> pp[i].n >> pp[i].a >> pp[i].w;
  }

  sort(pp, pp + n, [](P &l, P &r) {
    return l.w > r.w || (l.w == r.w && l.a < r.a) || (l.w == r.w && l.a == r.a && l.n < r.n);
  });

  for (int _ = 0; _ < k; _++) {
    int m, amin, amax;
    cin >> m >> amin >> amax;
    cout << "Case #" << _ + 1 << ":\n";
    int c = 0;
    for (int i = 0; i < n && c < m; i++) {
      if (pp[i].a >= amin && pp[i].a <= amax) {
        cout << pp[i].n << " " << pp[i].a << " " << pp[i].w << endl;
        c++;
      }
    }
    if (!c) cout << "None" << endl;
  }
}
