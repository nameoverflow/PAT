#include <unordered_map>
#include <cstdio>
#include <cmath>
#include <iostream>

using namespace std;

#define LOG(__t) cout << #__t": " << __t << endl
#define ull unsigned long long
union H {
  char c[5];
  ull l;
};

unordered_map<ull, int> rk;
unordered_map<ull, bool> qed;

bool isP(int n) {
  bool res = true;
  for (int i = 2; i <= sqrt(n); i++) {
    res = n % i != 0;
    if (!res) break;
  }
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    H f;
    scanf("%s", f.c);
    rk[f.l] = i + 1;
    qed[f.l] = false;
  }

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    H f;
    scanf("%s", f.c);
    printf("%s: ", f.c);
    if (qed.find(f.l) == qed.end()) {
      printf("Are you kidding?\n");
    } else if (qed[f.l] == true) {
      printf("Checked\n");
    } else {
      auto shit = rk[f.l];
      if (shit == 1) {
        printf("Mystery Award\n");
      } else if (isP(shit)) {
        printf("Minion\n");
      } else {
        printf("Chocolate\n");
      }
      qed[f.l] = true;
    }
  }
}
