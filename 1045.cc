#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cstring>

using namespace std;

int N, M, L;
int match[10010];
int pos[10010];
int rec[10010] = {0};
static int maxl = 0;

void solve() {
  rec[0] = -1;
  for (int i = 1; i < L + 1; i++) {
    if (match[i] == -1) continue;
    if (match[i] >= rec[maxl]) rec[++maxl] = match[i];
    else {
      auto it = upper_bound(rec, rec + maxl + 1, match[i]);
      // while (it < rec + maxl && *it == *(it + 1)) it++;
      *it = match[i];
    }

  }
}

int main() {
  cin >> N >> M;
  memset(pos, 0xff, sizeof(pos));
  memset(match, 0xff, sizeof(match));

  for (int i = 0; i < M; i++) {
    int c;
    cin >> c;
    pos[c] = i;
  }

  cin >> L;
  for (int i = 1; i < L + 1; i++) {
    int st;
    cin >> st;
    match[i] = pos[st];
  }

  solve();

  cout << maxl;
}