#include <cstdio>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>

using namespace std;
using P = pair<int, int>;
#define MP make_pair

const int MAXN = 20, MAXK = 1010;

int pt[MAXK], endt[MAXK];
queue<int> win[MAXN];
int N, M, K, Q;

int main() {
  scanf("%d %d %d %d", &N, &M, &K, &Q);

  priority_queue<P, vector<P>, greater<P>> pq;

  int i = 0;
  for (int tmpp = 0; i < K && win[tmpp % N].size() < M; i++, tmpp++) {
    scanf("%d", &pt[i]);
    // printf("%d -> %d\n", i, tmpp % N);
    win[tmpp % N].push(i);
  }
  for (int j = 0; j < N; j++) {
    // printf("%d: %d -> %d\n", j, win[j].front(), pt[win[j].front()]);
    if (win[j].size()) pq.push(MP(pt[win[j].front()], j));
  }

  for (; i < K; i++) {
    scanf("%d", &pt[i]);
    auto nxtw = pq.top().second, nxtt = pq.top().first;
    pq.pop();
    // curt[nxtw] = nxtt;
    endt[win[nxtw].front()] = nxtt;
    win[nxtw].pop();
    win[nxtw].push(i);
    // printf("%d %d %d\n", nxtt, nxtw, nxtt + pt[win[nxtw].front()]);
    pq.push(MP(nxtt + pt[win[nxtw].front()], nxtw));
  }

  while (pq.size()) {
    auto nxtw = pq.top().second, nxtt = pq.top().first;
    pq.pop();
    // curt[nxtw] = nxtt;
    endt[win[nxtw].front()] = nxtt;
    win[nxtw].pop();
    if (win[nxtw].size()) pq.push(MP(nxtt + pt[win[nxtw].front()], nxtw));
  }

  for (int i = 0; i < Q; i++) {
    int q;
    scanf("%d", &q);
    q--;
    // printf("%d\n", q);
    if (endt[q] - pt[q] < (17 - 8) * 60) {
      printf("%02d:%02d\n", endt[q] / 60 + 8, endt[q] % 60);
    } else {
      printf("Sorry\n");
    }
  }
}