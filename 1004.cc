#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>
#include <stack>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define LOG(__t) cout << ""#__t": " << __t << endl

#define MAXN (100+10)

typedef struct node {
  int ch = 0;
  int nxt = 0;
} node;

node tree[MAXN];

int main() {
  int max, num;
  scanf("%d %d", &max, &num);
  for (int i = 0; i < num; i++) {
    int p = 0, n, ch1, ch2;
    scanf("%d %d", &p, &n);
    scanf("%d", &ch2);
    tree[p].ch = ch2;
    for(int j = 1; j < n; j++) {
      ch1 = ch2;
      scanf("%d", &ch2);
      tree[ch1].nxt = ch2;
    }
  }

  deque<int> q;
  int count = 0;
  if (tree[1].ch) {
    printf("0");
  } else {
    printf("1");
  }
  if (!tree[1].ch) return 0;
  for (int c = tree[1].ch; c; q.push_back(c), c = tree[c].nxt);
  q.push_back(0);
  while (!q.empty()) {
    int c = q.front(); q.pop_front();
    if (c == 0) {
      printf(" %d", count);
      count = 0;
      if (!q.empty()) {
        q.push_back(0);
      }
      continue;
    }
    if (tree[c].ch) {
      for (int i = tree[c].ch; i; q.push_back(i), i = tree[i].nxt);
    } else {
      count++;
    }
  }

  // for (int cur = 1, first = 1;;) {
  //   int count = 0;
  //   while (!tree[first].ch && tree[first].nxt) {
  //     count++;
  //     first = tree[first].nxt;
  //   }
  //   cur = first;
  //   while (cur) {
  //     if (!tree[cur].ch) count++;
  //     cur = tree[cur].nxt;
  //   }
  //   if (first == 1) {
  //     printf("%d", count);
  //   } else {
  //     printf(" %d", count);
  //   }
  //   if (!tree[first].ch) break;
  //   cur = first = tree[first].ch;
  // }
}
