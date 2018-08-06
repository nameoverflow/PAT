#include <cstdio>
#include <vector>

using namespace std;

#define REP0(_i, _n) for(size_t _i = 0; _i < _n; _i++) 
#define REP1(_i, _n) for(size_t _i = 1; _i < _n; _i++) 
#define REPF(_i, _f, _n) for (size_t _i = _f; _i < _n; _i++)

bool ocu[1010][1010] = {0};

bool puton(int col, int row, int n) {
  if (ocu[col][row]) return false;
  // printf("cur (%d, %d)\n", col, row);
  ocu[col][row] = true;
  REP1(i, col) {
    int del = col - i;
    ocu[i][row] = true;
    if (row - del > 0) {
  // printf("(%d, %d)\n", i, row - del);
      ocu[i][row - del] = true;
    }
    if (row + del < n) {
  // printf("(%d, %d)\n", i, row + del);
      ocu[i][row + del] = true;
    }
  }
  REPF(i, col + 1, n + 1) {
    int del = i - col;
    ocu[i][row] = true;
    if (row - del > 0) {
  // printf("(%d, %d)\n", i, row - del);
      ocu[i][row - del] = true;
    }
    if (row + del < n) {
  // printf("(%d, %d)\n", i, row + del);
      ocu[i][row + del] = true;
    }
  }
  return true;
}

int main() {
  int k;
  scanf("%d", &k);
  REP0(_, k) {
    int n;
    scanf("%d", &n);
    REP1(i, n + 1) {
      REP1(j, n + 1) {
        ocu[i][j] = false;
      }
    }
    bool res = true;
    REP1(i, n + 1) {
      int cc;
      scanf("%d", &cc);
      res = res && puton(i, cc, n);
    }
    if (res) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
}
