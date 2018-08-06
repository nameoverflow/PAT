#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

using PII = pair<int, int>;
#define fi first
#define se second
#define MP make_pair

int N, L;
vector<int> fan[1010];
bool vis[1010];
int level[1010];
int visit(int st) {
  fill(level, level + N + 1, INT_MAX);

  queue<int> q;
  q.push(st);
  level[st] = 0;
  while (q.size()) {
    auto cc = q.front(); q.pop();
    for (auto n : fan[cc]) {
      // cout << cc << "->" << n << ":" << level[cc] << endl;
      if (level[cc] + 1 <= L && level[cc] + 1 < level[n]) {
        level[n] = level[cc] + 1;
        q.push(n);
      }
    }
  }

  int total = 0;
  for (int i = 1; i < N + 1; i++) {
    if (level[i] <= L) {
      // cout << i << "|" << level[i] << " ";
      total++;
    }
  }
  // cout << endl;
  return total;
}

int main() {
  cin >> N >> L;
  for (int i = 1; i < N + 1; i++) {
    int f;
    cin >> f;
    for (int k = 0; k < f; k++) {
      int ff;
      cin >> ff;
      fan[ff].push_back(i);
    }
  }

  int qn;
  cin >> qn;
  for (int i = 0; i < qn; i++) {
    int qq;
    cin >> qq;
    cout << visit(qq) - 1 << endl;
  }
}