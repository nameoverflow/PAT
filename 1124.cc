#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
  cin.sync_with_stdio(false);
  int m, n, s;
  cin >> m >> n >> s;

  int c = n;
  set<string> cand;
  for (int i = 0; i < m; i++) {
    string name;
    cin >> name;
    if (s > 1) {
      s--;
      continue;
    }
    if (c == n) {
      if (cand.find(name) != cand.end()) continue;
      cout << name << '\n';
      cand.insert(name);
      c = 0;
    }
    c++;
  }

  if (cand.empty()) {
    cout << "Keep going...";
  }
}
