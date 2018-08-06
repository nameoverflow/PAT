#include <cstdio>
#include <stack>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct N {
  int l, r;
  string d;
};

N tree[22];
int p[22] = {0};

void dfs(int st) {
  if (st == -1) return;
  if (tree[st].l == -1 && tree[st].r == -1) {
    cout << tree[st].d;
    return;
  }
  cout << "(";
  dfs(tree[st].l);
  cout << tree[st].d;
  dfs(tree[st].r);
  cout << ")";
}

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n + 1; i++) {
    cin >> tree[i].d >> tree[i].l >> tree[i].r;
    if (tree[i].l > 0) p[tree[i].l] = i;
    if (tree[i].r > 0) p[tree[i].r] = i;
  }

  int st = 1;
  while (p[st]) st = p[st];

  dfs(tree[st].l);
  cout << tree[st].d;
  dfs(tree[st].r);
}
