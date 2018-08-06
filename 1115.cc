#include <cstdio>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define PII pair<int, int>
#define MP make_pair
#define fi first
#define se second

vector<PII> tr;
vector<int> nm;

void insert(int p, int n) {
  // printf("%d %d\n", p, n);
  if (nm[n] > nm[p]) {
    if (tr[p].se != -1) insert(tr[p].se, n);
    else tr[p].se = n;
  } else {
    if (tr[p].fi != -1) insert(tr[p].fi, n);
    else tr[p].fi = n;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  tr.reserve(n);
  nm.reserve(n);
  int cc;
  scanf("%d", &cc);
  tr.push_back(MP(-1, -1));
  nm.push_back(cc);
  for (int i = 1; i < n; i++) {
    scanf("%d", &cc);
    tr.push_back(MP(-1, -1));
    nm.push_back(cc);
    insert(0, i);
  }


  queue<PII> seq;
  int cur = 0, pre = 0, lv = 1;
  seq.push(MP(0, 1));
  while (seq.size()) {
    PII nn = seq.front(); seq.pop();
    // printf("%d %d\n", nm[nn.fi], nn.se);
    if (nn.fi == -1) continue;
    if (nn.se > lv) {
      pre = cur;
      cur = 1;
      lv = nn.se;
    } else {
      cur++;
    }
    seq.push(MP(tr[nn.fi].fi, nn.se + 1));
    seq.push(MP(tr[nn.fi].se, nn.se + 1));
  }

  printf("%d + %d = %d", cur, pre, pre + cur);
}

