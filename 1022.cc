#include <set>
#include <vector>
#include <string>
#include <unordered_map>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
#define LOG(__t) cout << ""#__t": " << __t << endl

unordered_map<string, set<long>> q[5];
char buf[100];
int main() {
  int N;
  gets(buf);
  sscanf(buf, "%d", &N);
  for (int i = 0; i < N; i++) {
    long id;
    char s[82];
    gets(buf);
    sscanf(buf, "%ld", &id);
    gets(s);
    q[0][s].insert(id);
    gets(s);
    q[1][s].insert(id);
    gets(buf);
    auto dli = strtok(buf, " ");
    while (dli) {
      q[2][dli].insert(id);
      dli = strtok(NULL, " ");
    }
    gets(s);
    q[3][s].insert(id);
    gets(s);
    q[4][s].insert(id);
  }

  int qn;
  gets(buf);
  sscanf(buf, "%d", &qn);
  for (int i = 0; i < qn; i++) {
    int ty;
    gets(buf);
    sscanf(buf, "%d", &ty);
    printf("%s\n", buf);
    char *t = buf;
    while (*t != ' ') t++;
    t++;
    auto it = q[ty - 1].find(t);
    if (it != q[ty - 1].end()) {
      for (auto &id : (*it).second) {
        printf("%07ld\n", id);
      }
    } else {
      printf("Not Found\n");
    }
  }
}

