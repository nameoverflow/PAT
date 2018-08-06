#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <queue>

using namespace std;

struct T {
  int l = -1, r = -1;
};

T tr[110];
int cnt[110];
int all[110];

int cur = 0;
void ino(int r) {
  if (r == -1) return;
  ino(tr[r].l);
  cnt[r] = all[cur++];
  ino(tr[r].r);
}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> tr[i].l >> tr[i].r;
  }

  for (int i = 0; i < n; i++) {
    cin >> all[i];
  }

  sort(all, all + n, less<int>());

  ino(0);

  queue<int> q;

  q.push(0);
  bool flag = true;
  while (q.size()) {
    auto cc = q.front(); q.pop();
    if (cc == -1) continue;
    if (flag) flag = false;
    else cout << ' ';
    cout << cnt[cc];
    q.push(tr[cc].l);
    q.push(tr[cc].r);
  }

}
