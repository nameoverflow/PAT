#include <cstdio>

bool vis[100000] = {0};
int nxt[100000];

int main() {
  int s1, s2, n;
  char s[3];
  scanf("%d%d%d", &s1, &s2, &n);

  for (int i = 0; i < n; i++) {
    int p, c, n;
    scanf("%d %s %d", &p, s, &n);

    nxt[p] = n;
  }

  auto cur = s1;
  while (cur != -1) {
    // printf("%05d\n", cur);
    vis[cur] = 1;
    cur = nxt[cur];
  }

  cur = s2;
  while (cur != -1) {
    // printf("%05d\n", cur);
    if (vis[cur]) {
      printf("%05d", cur);
      return 0;
    }
    cur = nxt[cur];
  }
  printf("-1");
}
