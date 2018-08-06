#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;

typedef unsigned long long ull;

#define LOG(__t) cout << ""#__t": " << __t << endl

class Time {
public:
  int h;
  int m;
  int s;
  Time(){};
  Time(int _h, int _m):h(_h), m(_m) {};
  Time(int _h, int _m, int _s):h(_h), m(_m), s(_s) {};
  Time operator+(Time &r) {
    Time t(h + r.h, m + r.m, s + r.s);
    if (t.s > 59) {
      t.s -= 60;
      t.m += 1;
    }
    if (t.m > 59) {
      t.m -= 60;
      t.h += 1;
    }
    return t;
  }
  Time operator+(int _m) {
    Time t(h, m, s);
    if (t.m > 59) {
      t.m -= 60;
      t.h += 1;
    }
    return t;
  }
  int operator-(Time &r) {
    Time t(h, m, s);
    t.s -= r.s;
    if (t.s < 0) {
      t.s += 60;
      t.m -= 1;
    }
    t.m -= r.m;
    if (t.m < 0) {
      t.m += 60;
      t.h -= 1;
    }
    t.h -= r.h;
    return t.h * 60 + t.m + (t.s != 0);
  }
  void operator+= (Time &r) {
    h += r.h;
    m += r.m;
    s += r.s;
    if (s > 59) {
      s -= 60;
      m += 1;
    }
    if (m > 59) {
      m -= 60;
      h += 1;
    }
  }
  void operator+= (int _m) {
    m += _m;
    if (m > 59) {
      m -= 60;
      h += 1;
    }
  }
  bool operator< (Time &r) {
    return h < r.h || (h == r.h && m < r.m) || (h == r.h && m == r.m && s < r.s);
  }
  bool operator==(Time &r) {
    return h == r.h && m == r.m && s == r.s;
  }
  bool operator<= (Time &r) {
    return *this < r || *this == r;
  }
};

typedef struct ent {
  Time t;
  int l;
  bool v;
  int num;
  bool operator< (struct ent &r) {
    return t < r.t;
  }
} ent;

class MoreEnt {
  public:
  bool operator() (ent *l, ent *r) {
    return !(l->t < r->t);
  }
};

struct Table {
  Time end = Time(8, 0, 0);
  int num;
  int serv = 0;
  bool vip = false;;
};

class MoreTable {
  public:
  bool operator() (Table *l, Table *r) {
    return !(l->end < r->end);
  }
};
class CompareReadyTable {
  public:
  bool operator() (Table *l, Table *r) {
    return l->num > r->num;
  }
};

int main() {
  int N = 0, K = 0, M = 0;
  ent ent_in;
  cin >> N;

  vector<ent> ents(N);
  vector<bool> mark(N);
  priority_queue<ent*, vector<ent*>, MoreEnt> pq;
  priority_queue<ent*, vector<ent*>, MoreEnt> vips;

  for (int i = 0; i < N; i++) {
    ent &cur = ents[i];
    scanf("%d:%d:%d %d %d", &cur.t.h, &cur.t.m, &cur.t.s, &cur.l, &cur.v);
    cur.num = i;
    mark[i] = true;
    pq.push(&cur);
    if (cur.v) vips.push(&cur);
  }

  cin >> N >> K;
  
  vector<Table> tbls(N);
  priority_queue<Table*, vector<Table*>, MoreTable> pq_tbl;
  priority_queue<Table*, vector<Table*>, CompareReadyTable> tbl_ready;

  for (int i = 0; i < N; i++) {
    tbls[i].num = i + 1;
    pq_tbl.push(&tbls[i]);
  }

  for (int i = 0; i < K; i ++) {
    int f;
    cin >> f;
    tbls[f - 1].vip = true;
  }

  Time curt(8, 0, 0);
  Time endt(21, 0, 0);

  while (curt < endt && !pq.empty()) {
    ent *next = NULL;
    while (!pq.empty()) {
      next = pq.top();
      if (mark[next->num]) {
        break;
      }
      pq.pop();
      next = NULL;
    }
    if (next == NULL) break;

    if (curt < next->t) {
      curt = next->t;
    }

    while (!pq_tbl.empty() && pq_tbl.top()->end <= curt) {
      tbl_ready.push(pq_tbl.top());
      pq_tbl.pop();
    }

    if (tbl_ready.empty()) {
      curt = pq_tbl.top()->end;
      tbl_ready.push(pq_tbl.top());
      pq_tbl.pop();
    }

    if (endt <= curt) break;

    if (tbl_ready.top()->vip) {
      while (!vips.empty() && !mark[vips.top()->num]) {
        vips.pop();
      }
      if (!vips.empty() && vips.top()->t <= curt) {
        next = vips.top(); vips.pop();
      } 
    } else {
      pq.pop();
    }
    mark[next->num] = false;
    Table *cur = tbl_ready.top();
    tbl_ready.pop();

    printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", next->t.h, next->t.m, next->t.s, curt.h, curt.m, curt.s, curt - next->t);
    cur->end = next->t;
    cur->end += next->l;
    pq_tbl.push(cur);
    cur->serv++;

  }

  for (int i = 0; i < N - 1; i++) {
    cout << tbls[i].serv << " ";
  }
  cout << tbls[N - 1].serv;

}
