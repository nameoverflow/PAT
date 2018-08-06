#include <cstdio>
#include <limits>
#include <map>
#include <queue>
#include <functional>

using namespace std;

#define MP make_pair

using ul = unsigned long;
using P = pair<ul, ul>;
using PQ = priority_queue<P, vector<P>, less<P>>;
using MAP = map<ul, pair<ul, char>>;


void update(PQ &pq, MAP &r, char t) {
  ul rk = 0, count = 1;;
  ul pre = 101;
  while (pq.size()) {
    auto cur = pq.top(); pq.pop();
    if (cur.first != pre) {
      rk += count;
      count = 1;
    } else {
      count ++;
    }
    pre = cur.first;
    auto curit = r.find(cur.second);
    if (curit == r.end() || (*curit).second.first >= rk) {
      r[cur.second] = MP(rk, t);
    }
  }
}

int main() {
  int _M, _N;
  scanf("%d %d", &_N, &_M);

  MAP ranks;
  PQ A, C, M, E;
  for (size_t i = 0; i < _N; i++) {
    ul s, c, m, e, a;
    scanf("%lu %lu %lu %lu", &s, &c, &m, &e);
    a = ((double)(c + m + e) / 3 + 0.49);
    C.push(MP(c, s));
    M.push(MP(m, s));
    E.push(MP(e, s));
    A.push(MP(a, s));
  }
  update(E, ranks, 'E');
  update(M, ranks, 'M');
  update(C, ranks, 'C');
  update(A, ranks, 'A');

  for (size_t i = 0; i < _M; i++) {
    ul c;
    scanf("%lu", &c);
    auto it = ranks.find(c);
    if (it == ranks.end()) {
      printf("N/A\n");
    } else {
      printf("%lu %c\n", (*it).second.first, (*it).second.second);
    }
  }
}