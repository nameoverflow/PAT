#include <cstdio>
#include <map>
#include <functional>

using namespace std;

char inp[1010];
map<char, int> st;
map<char, int> od;
int main() {
  int n;
  scanf("%d %s", &n, inp);

  int rep = 1;
  for (int i = 1; inp[i - 1]; i++) {
    if (inp[i] == inp[i - 1]) rep++;
    else {
      if (rep % n == 0) {
        if (st[inp[i - 1]] == 0) {
          od[inp[i - 1]] = i - 1;
          st[inp[i - 1]] = n;
        }
      } else {
        st[inp[i - 1]] = -1;
      }
      rep = 1;
    }
  }

  map<int, char> res;
  for (auto &v : st) {
    if (v.second == n) {
      res[od[v.first]] = v.first;
    }
  }

  for (auto &v : res) {
    printf("%c", v.second);
  }
  if (st.size()) printf("\n");
  for (int i = 0; inp[i]; i++) {
    if (st[inp[i]] == n) i += n - 1;
    printf("%c", inp[i]);
  }
}
