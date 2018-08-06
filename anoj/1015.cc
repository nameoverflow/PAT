#include <vector>
#include <utility>
#include <cstdio>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
#define PII pair<int, int>
#define MP make_pair
#define fi first
#define se second


PII tr[33];
string nn[33];
int pa[33];

double eval(int root) {
  if (root == -1) return 0;
  auto l = eval(tr[root].fi);
  auto r = eval(tr[root].se);
  switch(nn[root][0]) {
  case '+': return l + r;
  case '-': return l - r;
  case '*': return l * r;
  case '/': return l / r;
  default: return (double)(stoi(nn[root]));
  }
}

void format(int root, bool paren) {
  // printf("%d", tr[root].fi);
  if (root == -1) return;
  if (isdigit(nn[root][0])) {
    printf("%s", nn[root].c_str());
    return;
  }
  if (paren) printf("(");
  format(tr[root].fi, true);
  printf("%s", nn[root].c_str());
  format(tr[root].se, true);
  if (paren) printf(")");
}

int main() {
  int n;
  scanf("%d", &n);
  if (n == 0) {
    printf("0 0.00");
    return 0;
  }
  for (int i = 0; i < n; i++) {
    char buf[10];
    scanf("%s", buf);
    nn[i] = buf;
  }
  fill(tr, tr + n, MP(-1, -1));
  fill(pa, pa + n, -1);
  for (int i = 0; i < n; i++) {
    char a[10], b[10];
    // while((a = getchar()) && isspace(a));
    // while((b = getchar()) && isspace(b));
    scanf("%s %s", a, b);
    if (a[0] != '-') {
      tr[i].fi = atoi(a);
      pa[tr[i].fi] = i;
    }
    if (b[0] != '-') {
      tr[i].se = atoi(b);
      pa[tr[i].se] = i;
    }
    // printf("%c %c\n", a[0], b[0]);
  }

  int root = 0;
  while(pa[root] != -1) root = pa[root];

  format(root, false);
  printf(" %.2lf", eval(root));
}