#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <functional>
#include <set>
#include <stack>
#include <string>

using namespace std;

map<string, int> trace;
vector<string> intern;
int in(string &n) {
  if (trace.find(n) == trace.end()) {
    trace[n] = intern.size();
    intern.push_back(n);
  }
  return trace[n];
}

string tr(int n) {
  return intern[n];
}

using PII = pair<int, int>;
#define fi first
#define se second
#define MP make_pair

// vector<PII> g[1010];
map<int, int> g[5000];
bool counted[5000][5000] = {0};
set<int> node;
int N, K;
map<string, int> heads;

void solve() {
  stack<int> sk;
  while (node.size()) {
    auto first = *node.begin();
    int count = 0;
    int maxc = 0;
    int total = 0;
    int head;
    sk.push(first);
    while (sk.size()) {
      auto cur = sk.top(); sk.pop();
      if (node.find(cur) == node.end()) continue;
      node.erase(cur);
      count++;
      int cc = 0;
      for (auto nxt : g[cur]) {
        // cout << tr(nxt.fi) << " " << nxt.se << endl;
        sk.push(nxt.fi);
        cc += nxt.se;
        if (!counted[cur][nxt.fi])
          total += nxt.se;
        counted[cur][nxt.fi] = 1;
        counted[nxt.fi][cur] = 1;
      }
      if (cc > maxc) {
        head = cur;
        maxc = cc;
      }
    }
    // cout << count << " " << 
    if (count > 2 && total > K) {
      heads[tr(head)] = count;
    }
    // cout << endl;
  }
}

int main() {
  cin >> N >> K;
  while (N--) {
    string ft, to;
    int v;
    cin >> ft >> to >> v;
    int ff = in(ft), tt = in(to);
    g[ff][tt] += v;
    g[tt][ff] += v;
    node.insert(ff);
    node.insert(tt);
  }

  solve();

  cout << heads.size() << endl;
  for (auto &hh : heads) {
    cout << hh.fi << " " << hh.se << endl;
  }
}
