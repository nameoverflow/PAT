#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>


using namespace std;

struct Time {
  int h; int m; int s;
  bool operator< (Time &r) {
    return h < r.h || (h == r.h && m < r.m) || (h == r.h && m == r.m && s < r.s);
  }
};

struct S {
  int n; Time s; Time e;
};

class LtE {
public:
  bool operator()(S *l, S *r) {
    return l->e < r->e;
  }
};
class GtS {
public:
  bool operator()(S *l, S *r) {
    return r->s < l->s;
  }
};

int main () {
  int N;
  scanf("%d", &N);
  vector<char[20]> id(N);
  vector<S> s(N);
  priority_queue<S*, vector<S*>, LtE> leave;
  priority_queue<S*, vector<S*>, GtS> come;

  for (int i = 0; i < N; i++) {
    s[i].n = i;
    scanf("%s %d:%d:%d %d:%d:%d", id[i], &s[i].s.h, &s[i].s.m, &s[i].s.s, &s[i].e.h, &s[i].e.m, &s[i].e.s);
    come.push(&s[i]);
    leave.push(&s[i]);
  }

  printf("%s %s", id[come.top()->n], id[leave.top()->n]);

}

