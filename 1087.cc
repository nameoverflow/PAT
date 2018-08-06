#include <unordered_map>
#include <vector>
#include <set>
#include <functional>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <climits>
#include <iostream>
#include <cmath>

using namespace std;

#define P pair<int, int>
#define MP make_pair
#define fi first
#define se second

int N;
struct E {
  int to, di;
};
vector<E> g[220];
vector<string> intern;
map<string, int> trace;

int in(string s) {
  if (trace.find(s) == trace.end()) {
    trace[s] = intern.size();
    intern.push_back(s);
  }
  return trace[s];
}

string tr(int i) {
  return intern[i];
}

int dis[220];
int hap[220];
vector<int> pre[220];

void dijkst(int st) {
  priority_queue<P, vector<P>, greater<P>> pq;
  
  fill(dis, dis + N, INT_MAX);
  dis[st] = 0;
  pq.push(MP(0, st));

  while (pq.size()) {
    auto du = pq.top().first, u = pq.top().second;
    pq.pop();
    if (du > dis[u]) continue;
    for (auto v : g[u]) {
      if (du + v.di < dis[v.to]) {
        dis[v.to] = du + v.di;
        pre[v.to] = { u };
        pq.push(MP(dis[v.to], v.to));
      } else if (du + v.di == dis[v.to]) {
        pre[v.to].push_back(u);
      }
    }
  }
}

vector<int> maxp;
vector<int> path;
int countp = 0;
int maxh = 0;
void dfs(int r, int sumh) {
  if (r == 0) {
    countp++;
    if (sumh > maxh || (sumh == maxh && path.size() < maxp.size())) {
      maxh = sumh;
      maxp = path;
    }
  }
  for (auto n : pre[r]) {
    path.push_back(n);
    dfs(n, sumh + hap[n]);
    path.pop_back();
  }
}

int main() {
  int m, st;
  string ss;
  cin >> N >> m >> ss;
  st = in(ss);

  for (int i = 0; i < N - 1; i++) {
    string c; int h;
    cin >> c >> h;
    hap[in(c)] = h;
  }
  for (int i = 0; i < m; i++) {
    string fs, ts;
    int fr, to, d;
    cin >> fs >> ts >> d;
    fr = in(fs); to = in(ts);
    g[fr].push_back({ to, d });
    g[to].push_back({ fr, d });
  }

  int rom = in("ROM");

  dijkst(st);

  dfs(rom, hap[rom]);

  cout << countp << " " << dis[rom] << " " << maxh << " " << (int)(1.0 * maxh / maxp.size()) << '\n';
  for (auto it = maxp.rbegin(); it != maxp.rend(); it++) {
    cout << tr(*it) << "->";
  }
  cout << "ROM";
}
