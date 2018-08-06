#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

vector<int> tr[110];
int cnt[110];
vector<string> paths;
string tpath;
void dfs(int p, int d, int acc) {
  tpath.push_back(cnt[p]);
  if (tr[p].empty() && acc == d) {
    paths.push_back(tpath);
  }
  for (auto ch : tr[p]) {
    // cout << p << "->" << ch << ":" << cnt[ch] << ", " << acc + cnt[ch] << endl;
    dfs(ch, d, acc + cnt[ch]);
  }
  tpath.pop_back();
}

int main() {
  int n, m, s;
  cin >> n >> m >> s;
  for (int i = 0; i < n; i++) {
    cin >> cnt[i];
  }

  for (int i = 0; i < m; i++) {
    int nd, cc;
    cin >> nd;
    cin >> cc;
    for (int j = 0; j < cc; j++) {
      int nx;
      cin >> nx;
      tr[nd].push_back(nx);
    }
  }

  dfs(0, s, cnt[0]);

  sort(paths.begin(), paths.end(), greater<string>());

  for (auto &p : paths) {
    cout << int(p[0]);
    // for (auto c : p.substr(1)) {
    for (auto c : p.substr(1)) {
      cout << " " << int(c);
    }
    cout << endl;
  }
  
}
