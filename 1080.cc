// #include <queue>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct S {
  int f;
  int e, i;
  vector<int> ch;
};

vector<int> sch[110];
int quo[110];

S stu[40010];
int rk[40010];

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d", &quo[i]);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d %d", &stu[i].e, &stu[i].i);
    stu[i].f = (stu[i].e + stu[i].i) / 2;
    stu[i].ch.reserve(k);
    for (int j = 0; j < k; j++) {
      int c;
      scanf("%d", &c);
      stu[i].ch.push_back(c);
    }
  }
  for (int i = 0; i < n; i++) {
    rk[i] = i;
  }
  sort(rk, rk + n, [](int l, int r) {
    return stu[l].f > stu[r].f || (stu[l].i == stu[r].i && stu[l].e > stu[r].e);
  });

  for (int i = 0; i < n; i++) {
    S &ss = stu[rk[i]];
    for (auto ch : ss.ch) {
      if (sch[ch].size() < quo[ch]) {
        sch[ch].push_back(rk[i]);
        break;
      } else {
        S &last = stu[sch[ch].back()];
        if (last.f == ss.f && last.i == ss.i) {
          sch[ch].push_back(rk[i]);
          break;
        }
      }
    }
  }

  for (int i = 0; i < m; i++) {
    bool flag = 1;
    sort(sch[i].begin(), sch[i].end());
    for (auto s : sch[i]) {
      if (!flag) printf(" ");
      printf("%d", s);
      flag = 0;
    }
    printf("\n");
  }
  // if (sch[m - 1].empty()) printf("\n");

}