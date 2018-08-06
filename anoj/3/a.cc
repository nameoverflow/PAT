#include <set>
#include <cstdio>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

int main() {
  set<char> cl;
  int n;
  scanf("%d", &n);

  int total = 0;

  for (int i = 0; i < n; i++) {
    char wld[110];
    scanf("%s", wld);
    cl.clear();
    for (int c = 0; wld[c]; c++) {
      if (isalpha(wld[c]))
      cl.insert(wld[c]);
    }
    total += cl.size();
  }

  printf("%d", total);
}
