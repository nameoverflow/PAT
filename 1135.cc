#include <cstdio>
#include <vector>
#include <stack>
#include <utility>
#include <cmath>

using namespace std;

#define REP(__i, __n) for (size_t __i = 0; __i < __n; __i++)
#define REP1(__i, __n) for (size_t __i = 1; __i < __n; __i++)
#define PII pair<int, int>
#define fi first
#define se second


PII tree[33];
int cnt[33];

void insert(int c, int p) {
  if (abs(cnt[c]) > abs(cnt[p])) {
    if (tree[p].se) {
      insert(c, tree[p].se);
    } else {
      tree[p].se = c;
    }
  } else {
    if (tree[p].fi) {
      insert(c, tree[p].fi);
    } else {
      tree[p].fi = c;
    }
  }
}

int isrbt(int p) {
  if (!p) return 1;
  // printf("%d -> %d | %d\n", cnt[p], cnt[tree[p].fi], cnt[tree[p].se]);
  if (cnt[p] < 0) {
    if (tree[p].fi && cnt[tree[p].fi] < 0) return -1;
    if (tree[p].se && cnt[tree[p].se] < 0) return -1;
  }
  
  int l = isrbt(tree[p].fi);
  int r = isrbt(tree[p].se);
  if (l == -1 || r == -1 || l != r) return -1; 
  return l + !(cnt[p] < 0);
}

int main() {
  int k, n;
  scanf("%d", &k);

  REP(_, k) {
    scanf("%d", &n);
    fill(tree, tree + n, make_pair(0, 0));
    scanf("%d", &cnt[1]);
    REP1(i, n) {
      scanf("%d", &cnt[i + 1]);
      insert(i + 1, 1);
    }

    if (cnt[1] < 0 || isrbt(1) < 0) {
      printf("No\n");
    } else {
      printf("Yes\n");
    }
  }
}

