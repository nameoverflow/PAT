#include <iostream>
#include <queue>

using namespace std;

struct T {
  int l = -1, r = -1;
};

T tree1[33];
int cn1[33];
T tree2[33];
int cn2[33];

void insert(int p, int i, T tr[], int cn[]) {
  if (cn[i] > cn[p]) {
    if (tr[p].r == -1) {
      tr[p].r = i;
    } else insert(tr[p].r, i, tr, cn);
  } else {
    if (tr[p].l == -1) {
      tr[p].l = i;
    } else insert(tr[p].l, i, tr, cn);
  }
}

bool comp(int p1, int p2) {
  if (p1 == -1 && p2 == -1) return true;
  if ((p1 == -1 && p2 != -1) || (p1 != -1 && p2 == -1)) return false;
  if (cn1[p1] != cn2[p2]) return false;
  return comp(tree1[p1].l, tree2[p2].l) && comp(tree1[p1].r, tree2[p2].r);
}

void poo(int r) {
  static bool flag = 0;
  if (r == -1) return;
  poo(tree1[r].l);
  poo(tree1[r].r);
  if (flag) cout << " ";
  flag = true;
  cout << cn1[r];
}

void lv() {
  queue<int> q;
  q.push(1);
  bool flag = 0;
  while (q.size()) {
    auto cur = q.front(); q.pop();
    if (cur < 0) continue;
    if (flag) cout << " ";
    flag = true;
    cout << cn1[cur];
    q.push(tree1[cur].l);
    q.push(tree1[cur].r);
  }
}

int main() {
  int n;
  cin >> n;
  cin >> cn1[1];
  for (int i = 2; i < n + 1; i++) {
    cin >> cn1[i];
    insert(1, i, tree1, cn1);
  }
  cin >> cn2[1];
  for (int i = 2; i < n + 1; i++) {
    cin >> cn2[i];
    insert(1, i, tree2, cn2);
  }

  cout << (comp(1, 1) ? "YES" : "NO") << endl;

  poo(1);
  cout << endl;
  lv();
}
