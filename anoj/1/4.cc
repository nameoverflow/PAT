#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct T {
  int r = -1, l = -1;
};

// int lvo[33];
int ino[33];

int n;

T tr[33];

int build(int ins, vector<int> &lv) {
  if (lv.empty()) return -1;
  set<int> leftn;
  int p = lv[0];
  int inp = ins;
  for (; ino[inp] != p; inp++) {
    leftn.insert(ino[inp]);
  }
  vector<int> lvl, lvr;

  for (auto n : lv) {
    if (leftn.find(n) != leftn.end()) {
      lvl.push_back(n);
    } else if (n != p) {
      lvr.push_back(n);
    }
  }
  tr[inp].l = build(ins, lvl);
  tr[inp].r = build(inp + 1, lvr);
  
  return inp;
}

void pre(int r) {
  if (r == -1) return;
  static bool flag = 0;
  if (flag) cout << " ";
  flag = true;
  cout << ino[r];
  pre(tr[r].l);
  pre(tr[r].r);
}
void pos(int r) {
  if (r == -1) return;
  static bool flag = 0;
  pos(tr[r].l);
  pos(tr[r].r);
  if (flag) cout << " ";
  flag = true;
  cout << ino[r];
}

int main() {
  cin >> n;

  vector<int> lvo(n);
  for (int i = 0; i < n; i++) {
    cin >> lvo[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> ino[i];
  }

  int p = build(0, lvo);

  pre(p);
  cout << endl;
  pos(p);
}
