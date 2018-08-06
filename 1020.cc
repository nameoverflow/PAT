#include <cstdio>
#include <utility>
#include <queue>


using namespace std;

#define MAXN (33)

int post[MAXN] = {0};
int in[MAXN] = {0};

struct T {
  int left;
  int right;
  int cnt;
};
vector<T> tree;

int build(int sp, int ep, int si, int ei)
{
  if (si > ei) return -1;
  if (si == ei) {
    tree.push_back({-1, -1, in[si]});
    return tree.size() - 1;
  }
  int parent = post[ep];
  int i = si;
  while (i < ei) {
    if (in[i] == parent) break;
    i++;
  }
  tree.push_back({build(sp, i - 1 - si + sp, si, i - 1), build(i - si + sp, ep - 1, i + 1, ei), parent});
  return tree.size() - 1;
}

int main () {
  int N;
  scanf("%d", &N);
  if (N <= 0) return 0;
  tree.reserve(N * 2);
  for (int i = 0; i < N; i++) {
    scanf("%d", &post[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &in[i]);
  }

  int p = build(0, N - 1, 0, N - 1);

  queue<int> q;
  printf("%d", tree[p].cnt);
  q.push(tree[p].left);
  q.push(tree[p].right);
  while (!q.empty()) {
    int c = q.front(); q.pop();
    if (c < 0) continue;
    printf(" %d", tree[c].cnt);
    
    q.push(tree[c].left);
    q.push(tree[c].right);
  }
}
