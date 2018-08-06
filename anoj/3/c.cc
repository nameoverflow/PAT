#include <set>
#include <stack>
#include <utility>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


bool vis[10010] = {0};
vector<int> tr[10010];
int ty[10010];

using ull = unsigned long long;

string add(string &l, string &r) {
  string &b = l.size() >= r.size() ? l : r;
  string &s = l.size() >= r.size() ? r : l;
  string res;
  int c = 0;
  // cout << b << "+" << s << "=";
  for (int i = 0; i < s.size(); i++) {
    char t = b[b.size() - 1 - i] + s[s.size() - 1 - i] - '0' - '0' + c;
    c = t / 10;
    t %= 10; t += '0';
    res.push_back(t);
  }
  for (int i = b.size() - s.size() - 1; i >= 0; i--) {
    char t = b[i] + c - '0';
    c = t / 10;
    t %= 10; t += '0';
    res.push_back(t);
  }
  if (c) {
    res.push_back(c + '0');
  }
  while(res.size() > 1 && res.back() == '0') res.pop_back();
  reverse(res.begin(), res.end());
  // cout << res << endl;
  return res;
}

int main() {
  int n, m;
  set<int> all;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> ty[i];
    all.insert(i);
  }

  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    tr[l].push_back(r);
  }

  vector<string> res;

  while (all.size()) {
    int beg = *all.begin();
    stack<pair<int, string>> sk;
    all.erase(beg);
    sk.push(make_pair(beg, to_string(ty[beg])));
    string sum ;
    // cout << endl;
    while (sk.size()) {
      auto cur = sk.top(); sk.pop();
      if (tr[cur.first].empty()) {
        // cout << cur.second << endl;
        sum = add(sum, cur.second);
      }
      else {
        for (auto nxt : tr[cur.first]) {
          sk.push(make_pair(nxt, cur.second + to_string(ty[nxt])));
          all.erase(nxt);
        }
      }
    }
    // cout << sum;
    // if (all.size()) cout << " ";
    res.push_back(sum);
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    if (i != 0) cout << " ";
    cout << res[i];
  }
}
