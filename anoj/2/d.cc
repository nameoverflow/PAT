#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <cstring>

using namespace std;
using ull = unsigned long long;

#define REP(__i, __n) for(size_t __i = 0; __i < __n; __i++)

map<string, int> __trace;
vector<string> __intern;

string& tr(int const n) {
  return __intern[n];
}

int in(string const &&s) {
  if (__trace.find(s) == __trace.end())
    __trace[s] = __intern.size();
  return __trace[s];
}
int in(string const &s) {
  if (__trace.find(s) == __trace.end())
    __trace[s] = __intern.size();
  return __trace[s];
}

struct Pr {
  int s, ac = 0;
  vector<int> k;
} prblm[30];

enum ST {
  CE, AC, WA, PE, RE, TLE, MLE, OLE
};

struct Cmmt {
  int u, t, p;
  vector<ST> s;
} cmmt[20020];

struct User {
  double scr[26];
  int lst[26];
  int ep[26];
  int tp[26];
  int cep[26];
  int wcm[26];
  bool fb[26];
  bool ac[26];
  int rk;
};
map<int, User> user;


struct Res {
  int user, pnt;
  double src;
};
vector<Res> result;

char S1[22], S2[22], S3[22], S4[22];
ull N, M, P, E, G;

ST parse_st(char s) {
  switch(s) {
    case 'C': return CE;
    case 'A': return AC;
    case 'W': return WA;
    case 'P': return PE;
    case 'R': return RE;
    case 'T': return TLE;
    case 'M': return MLE;
    case 'O': return OLE;
  }
}

int main() {
  scanf("%s %s %s %s", S1, S2, S3, S4);

  bool icpc = !strcmp(S1, "icpc");
  enum { PA, AV, AL } scr_cnt;
  if (!strcmp(S2, "partial")) scr_cnt = PA;
  else if (!strcmp(S2, "average")) scr_cnt = AV;
  else scr_cnt = AL;


  scanf("%llu %llu %llu %llu %llu", &N, &M, &P, &E, &G);

  REP(i, M) {
    char bf[5];
    scanf("%s", bf);
    prblm[i].s = bf[0] - 'A';
    int k;
    scanf("%d", &k);
    REP(j, k) {
      int ss;
      scanf("%d", &ss);
      prblm[j].k.push_back(ss);
    }
  }

  REP(i, N) {
    auto &cc = cmmt[i];
    char bf[40], bfp[5];
    scanf("%s %d %s", bf, &cc.t, bfp);
    cc.p = bfp[0] - 'A';
    cc.u = in(bf);
    scanf("%s", bf);
    ST stt = parse_st(bf[0]);
    bool ac = stt == AC;
    double scr = ac ? prblm[cc.p].k[0] : 0;
    cc.s.push_back(stt);
    if (stt != CE) {
      for (int r = 1; r < prblm[cc.p].k.size(); r++) {
        scanf("%s", bf);
        auto nst = parse_st(bf[0]);
        if (nst != AC) ac = 0;
        else {
          if (scr_cnt == AV) scr += 100.0 / prblm[cc.p].k.size();
          else scr += prblm[cc.p].k[r];
        }
        cc.s.push_back(nst);
      }
    }
    if (scr_cnt == AL) scr = ac * 100;
    scr = scr / 100 * prblm[cc.p].s;
    if (ac) {
      if (prblm[cc.p].ac == 0) {
        user[cc.u].fb[cc.p] = 1;
      }
      prblm[cc.p].ac++;
    } else {
      if (!user[cc.u].ac[cc.p]) user[cc.u].wcm[cc.p]++;
    }
    if (scr > user[cc.u].scr[cc.p]) {
      scr = user[cc.u].scr[cc.p];
      if (!ac) {
        user[cc.u].ep[cc.p] += user[cc.u].cep[cc.p];
        user[cc.u].cep[cc.p] = 0;
      } else if (!strcmp(S3, "latest")) {
        user[cc.u].tp[cc.p] = cc.t / 60;
      }
      if (!strcmp(S3, "sum")) {
        user[cc.u].tp[cc.p] += cc.t / 60;
      }
    } else if (!ac) {
      user[cc.u].cep[cc.p] += 10;
    }
  }


  for (auto &u : user) {
    double scr = 0;
    int pnt = 0;
    REP(i, M) {
      if (icpc) u.second.scr[i] = u.second.scr[i] == 100;
      
      scr += u.second.scr[i];
      pnt += u.second.tp[i] + u.second.ep[i];
    }
    result.push_back({
      u.first, pnt, scr
    });
  }

  vector<int> rank(user.size());
  REP(i, rank.size()) {
    rank[i] = i;
  }
  sort(rank.begin(), rank.end(), [&](int l, int r) {
    return (result[l].src > result[r].src)
      || (result[l].src == result[r].src && result[l].pnt < result[r].pnt)
      || (result[l].src == result[r].src && result[l].pnt == result[r].pnt && tr(result[l].user) < tr(result[r].user));
  });

  REP(i, rank.size()) {
    user[rank[i]].rk = i;
  }

  bool filter_user = S4[0] == '-' && strlen(S4) == 1;
  if (filter_user) {
    printf("1\n");
  } else {
    printf("%d\n", __trace.size());
  }
  REP(i, M) {
    if (i != 0) printf(" ");
    printf("%d", prblm[i].ac);
  }
  printf("\n");

  if (filter_user) {
    int i = user[in(S4)].rk;
    auto &res = result[i];
    printf("%d %s %d %d", i + 1, tr(res.user), res.pnt);
    for (int j = 0; j < M; j++) {
      if (icpc) {
        printf("%d ", user[res.user].ac[j] ? 1 : 0);
      } else {
        printf("%.2lf ", user[res.user].scr[j]);
      }
      int h = user[res.user].lst[j] / 3600;
      int m = (user[res.user].lst[j] % 3600) / 60;
      int s = user[res.user].lst[j] % 60;
      printf("%02d:%02d:%02d %d %d %d\n", h, m, s, user[res.user].wcm[j], user[res.user].ac[j], user[res.user].fb[j]);
    }
  }
  for (size_t i = 0; i < rank.size(); i++) {
    auto &res = result[rank[i]];
    printf("%d %s %d %d", i + 1, tr(res.user), res.pnt);
    for (int j = 0; j < M; j++) {
      if (icpc) {
        printf("%d ", user[res.user].ac[j] ? 1 : 0);
      } else {
        printf("%.2lf ", user[res.user].scr[j]);
      }
      int h = user[res.user].lst[j] / 3600;
      int m = (user[res.user].lst[j] % 3600) / 60;
      int s = user[res.user].lst[j] % 60;
      printf("%02d:%02d:%02d %d %d %d\n", h, m, s, user[res.user].wcm[j], user[res.user].ac[j], user[res.user].fb[j]);
    }
  }
}

