#include <set>
#include <map>
#include <vector>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

set<int> hob[1010];
vector<int> user[1010];

bool all[1010] = {0};

int f[1010];
int find(int x)
{
  if(x != f[x]) f[x] = find(f[x]);
  return f[x];
}
int join(int x, int y) {
  f[find(x)] = f[find(y)];
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int k;
    scanf("%d:", &k);
    user[i].reserve(k);
    while (k--) {
      int h;
      scanf("%d", &h);
      user[i].push_back(h);
      hob[h].insert(i);
    }
  }

  vector<int> clus;
  for (int i = 0; i < n; i++) {
    if (all[i]) continue;
    all[i] = 1;
    int num = 1;
    set<int> hh(user[i].begin(), user[i].end());
    while (hh.size()) {
      auto it = *hh.begin();
      for (auto u : hob[it]) {
        if (all[u]) continue;
        all[u] = 1;
        num++;
        for (auto ho : user[u]) {
          hh.insert(ho);
        }
      }
      hh.erase(it);
    }
    clus.push_back(num);
  }

  sort(clus.begin(), clus.end(), greater<int>());
  printf("%d\n", clus.size());
  if (clus.size()) {
    printf("%d", clus[0]);
    for (int i = 1; i < clus.size(); i++) {
      printf(" %d", clus[i]);
    }
  }
}
