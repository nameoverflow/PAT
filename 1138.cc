#include <cstdio>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define PII pair<int, int>

#define MAXN (50000+10)

int in[MAXN] = {0};
int pre[MAXN] = {0};

PII tree[MAXN];

int det(int is, int ps, int len, int dp) {
  if (len <= 0) return -1;
  int p = pre[ps];
  int nxt = is;
  for (; nxt < is + len; nxt++) {
    if (p == in[nxt]) break;
  }
  int nl = nxt - is;

  int l = det(is, ps + 1, nl, dp + 1);
  int r = det(nxt + 1, ps + 1 + nl, len - nl - 1, dp + 1);

  tree[ps].first = l;
  tree[ps].second = r;
  return ps;
}

int main() {
  int N;
  scanf("%d", &N);
  fill(tree, tree + N, MP(-1, -1));

  for (int i = 0; i < N; i++) {
    scanf("%d", &pre[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &in[i]);
  }

  int p = det(0, 0, N, 0);

  for (;;) {
    if (tree[p].first == -1 && tree[p].second == -1) break;
    if (tree[p].first != -1) {
      p = tree[p].first;
      continue;
    }
    if (tree[p].second != -1) {
      p = tree[p].second;
      continue;
    }
  }

  printf("%d", pre[p]);
  
}
