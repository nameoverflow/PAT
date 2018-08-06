#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

#define PII pair<int, int>
#define MP make_pair
#define fi first
#define se second

PII tr[33];
int pr[33];
int po[33];
bool uni = true;
void build(int spr, int spo, int len) {
  if (len <= 1) return;

  int pa = spr;
  // printf("%d %d %d %d\n", pr[pa], spr, spo, len);
  int lcpr = spr + 1;
  int rcpo = spo + len - 2;
  if (pr[lcpr] != po[rcpo]) {
    int rcpr = spr + 1;
    for (; rcpr < spr + len - 1 && pr[rcpr] != po[rcpo]; rcpr++);
    int lcpo = spo;
    for (; lcpo < spo + len - 1 && po[lcpo] != pr[lcpr]; lcpo++);
    // printf("%d[%d] %d[%d]\n", lcpr, pr[lcpr], rcpo, po[rcpo]);

    // printf("%d[%d] %d[%d]\n", rcpr, pr[rcpr], lcpo, po[lcpo]);
    tr[pa].fi = lcpr;
    tr[pa].se = rcpr;

    int ln = rcpr - spr - 1;
    build(lcpr, spo, ln);
    build(rcpr, spo + ln, rcpo - lcpo);

  } else {
    uni = false;
    tr[pa].fi = lcpr;
    build(lcpr, spo, len - 1);
  }
}

bool flag = true;

void ino(int r) {
  if (r == -1) return;
  ino(tr[r].fi);
  if (flag) {
    printf("%d", pr[r]);
    flag = false;
  } else {
    printf(" %d", pr[r]);
  }
  ino(tr[r].se);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &pr[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &po[i]);
  }
  fill(tr, tr + n, MP(-1, -1));
  build(0, 0, n);
  puts(uni ? "Yes" : "No");
  ino(0);
  printf("\n");
}