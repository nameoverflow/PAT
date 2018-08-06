#include <iostream>
#include <stack>

using namespace std;

int m, n, l, t;

bool st[70][1300][200] = {0};
bool vis[70][1300][200] = {0};

// int vol = 0;
// void dfs(int z, int y, int x) {
//   if (z >= l || z < 0 || y >= m || y < 0 || x >= n || x < 0) return;
//   if (vis[z][y][x]) return;
//   vis[z][y][x] = 1;
//   if (!st[z][y][x]) return;
//   vol++;
//   dfs(z + 1, y, x);
//   dfs(z - 1, y, x);
//   dfs(z, y + 1, x);
//   dfs(z, y - 1, x);
//   dfs(z, y, x + 1);
//   dfs(z, y, x - 1);
// }

int dfs(int z, int y, int x) {
  int vol = 0;
  using P = struct { int z, y, x; };
  stack<P> sk;
  sk.push({ z, y, x });
  while (sk.size()) {
    auto pp = sk.top(); sk.pop();
    if (pp.z >= l || pp.z < 0 || pp.y >= m || pp.y < 0 || pp.x >= n || pp.x < 0) continue;
    if (vis[pp.z][pp.y][pp.x]) continue;
    vis[pp.z][pp.y][pp.x] = 1;
    if (!st[pp.z][pp.y][pp.x]) continue;
    vol++;
    sk.push({ pp.z + 1, pp.y, pp.x });
    sk.push({ pp.z - 1, pp.y, pp.x });
    sk.push({ pp.z, pp.y + 1, pp.x });
    sk.push({ pp.z, pp.y - 1, pp.x });
    sk.push({ pp.z, pp.y, pp.x + 1 });
    sk.push({ pp.z, pp.y, pp.x - 1 });
  }
  return vol;
}

int main() {
  cin >> m >> n >> l >> t;
  for (int z = 0; z < l; z++) {
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        cin >> st[z][y][x];
      }
    }
  }

  int total = 0;
  for (int z = 0; z < l; z++) {
    for (int y = 0; y < m; y++) {
      for (int x = 0; x < n; x++) {
        // vol = 0;
        int vol = dfs(z, y, x);
        if (vol >= t) {
          total += vol;
        }
      }
    }
  }

  cout << total;
}

