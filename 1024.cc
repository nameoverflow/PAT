#include <string>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string add(string &l, string &r) {
  string &s = l.size() <= r.size() ? l : r;
  string &h = l.size() <= r.size() ? r : l;

  string res;
  int cc = 0;
  for (int i = 0; i < s.size(); i++) {
    char tc = s[s.size() - i - 1] + h[h.size() - i - 1] + cc - '0' - '0';
    cc = tc / 10;
    res.push_back(tc % 10 + '0');
  }
  for (int i = s.size(); i < h.size(); i++) {
    char tc = h[h.size() - i - 1] - '0' + cc;
    cc = tc / 10;
    res.push_back(tc % 10 + '0');
  }
  if (cc) res.push_back(cc + '0');
  reverse(res.begin(), res.end());
  return res;
}

bool isp(string &n) {
  for (size_t i = 0; i < n.size() / 2 + 1; i++) {
    if (n[i] != n[n.size() - 1 - i]) return false;
  }
  return true;
}

int main() {
  string n; int k;
  cin >> n >> k;
  if (isp(n)) {
    cout << n << endl << 0;
    return 0;
  }

  for (int i = 1; i <= k; i++) {
    auto o = n;
    reverse(o.begin(), o.end());
    n = add(o, n);
    if (isp(n)) {
      cout << n << endl << i;
      return 0;
    }
  }
  cout << n << endl << k;
}