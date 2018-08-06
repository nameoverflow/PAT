#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
// #include <stack>
using namespace std;


int val[10010];
int n, m;

int d[10010] = {0};
bool sel[10010][10010] = {0};

void solve() {
  for (int i = 1; i < n + 1; i++) {
    for (int j = m; j >= val[i]; j--) {
      if (d[j] <= d[j - val[i]] + val[i]) {
        d[j] = d[j - val[i]] + val[i];
        sel[i][j] = 1;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> val[i + 1];
  }

  sort(val + 1, val + n + 1, greater<int>());
  solve();
  vector<int> res;
  if (d[m] != m) {
    cout << "No Solution";
  } else {
    int v = m, c = n;
    while (v > 0) {
      if (sel[c][v]) {
        res.push_back(val[c]);
        v -= val[c];
      }
      c--;
    }
    auto it = res.begin();
    cout << *it++;
    for (; it != res.end(); it++) {
      cout << " " << *it;
    }
  }
}
