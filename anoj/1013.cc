#include <cstdio>
#include <utility>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>

using namespace std;

#define PII pair<int, int>
#define MP make_pair
#define fi first
#define se second

struct NN {
  int idx;
  int ttd;
  int rtl;
  int rttld;
};

vector<int> lv;
vector<int> in;
vector<PII> tr;

int build(vector<int> &clv, int ins, int len) {
  if (len <= 1) return ins;
  int pv = clv[0];
  int p = ins;
  set<int> l;

  for (; p < ins + len && in[p] != pv; l.insert(in[p]), p++);
  vector<int> vl, vr;
  for (int i = 1; i < clv.size(); i++) {
    int j = ins;
    if (l.find(clv[i]) != l.end()) {
      vl.push_back(clv[i]);
    } else {
      vr.push_back(clv[i]);
    }
  }
  tr[p].fi = build(vl, ins, p - ins);
  tr[p].se = build(vr, p + 1, ins + len - p - 1);
  return p;
}

bool flag = false;
void pre(int r) {
  if (r == -1) return;
  printf(flag ? " %d" : "%d", in[r]);
  flag = true;
  pre(tr[r].fi);
  pre(tr[r].se);
}
void pos(int r) {
  if (r == -1) return;
  pos(tr[r].fi);
  pos(tr[r].se);
  printf(flag ? " %d" : "%d", in[r]);
  flag = true;
}

int main() {
  int n;
  scanf("%d", &n);
  lv.resize(n);
  in.resize(n);
  tr.resize(n);
  fill(tr.begin(), tr.end(), MP(-1, -1));
  for (int i = 0; i < n; i++) {
    scanf("%d", &lv[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &in[i]);
  }

  int root = build(lv, 0, n);

  flag = false;
  pre(root);
  printf("\n");
  flag = false;
  pos(root);
  printf("\n");

  stack<NN> sk;
  sk.push({ root, 0, 1, 1 });
  int ttdmax = 0, ttdmin = 0, rtlmax = 0, rttldmax = 0;
  while (sk.size()) {
    auto &cur = sk.top(); 
    if (cur.idx == -1) continue;
    ttdmax = max(cur.ttd, ttdmax);
    ttdmin = min(cur.ttd, ttdmin);
    rtlmax = max(cur.rtl, rtlmax);
    rttldmax = max(cur.rttld, rttldmax);

    sk.push({ tr[cur.idx].fi, cur.ttd - 1, cur.rtl + 1, cur.rttld });
    sk.push({ tr[cur.idx].se, cur.ttd + 1, cur.rtl + 1, cur.rttld + 1 });
    sk.pop();
  }

  printf("%d\n", rtlmax);
  printf("%d\n", rttldmax);
  printf("%d\n", ttdmax - ttdmin + 1);
}
