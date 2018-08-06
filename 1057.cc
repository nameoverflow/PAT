#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <functional>

using namespace std;

vector<int> sk;
multiset<int, greater<int>> lowers;
multiset<int> uppers;
int midv = 0;

void shrink() {
  int mid = sk.size();
  mid = mid % 2 == 0 ? mid / 2 : (mid + 1) / 2;
  while (lowers.size() > mid) {
    uppers.insert(*lowers.begin());
    lowers.erase(lowers.begin());
  }
  while (lowers.size() < uppers.size()) {
    lowers.insert(*uppers.begin()); 
    uppers.erase(uppers.begin());
  }
  // cout << "l: " << lowers.size() << " u: " << uppers.size() << " s: " << sk.size() << endl;
  if (sk.empty())
    midv = 0;
  else 
    midv = *lowers.begin();
}

int main() {
  int n;
  scanf("%d", &n);
  char cmd[15];
  int tmp;
  sk.reserve(n);
  while (n--) {
    scanf("%s", cmd);
    if (cmd[1] == 'o') {
      if (sk.size()) {
        int t = sk.back(); sk.pop_back();
        printf("%d\n", t);
        if (lowers.size() && t <= *lowers.begin()) lowers.erase(t);
        else uppers.erase(t);
      } else {
        printf("Invalid\n");
      }
    } else if (cmd[1] == 'u') {
      int t;
      scanf("%d", &t);
      sk.push_back(t);
      if (lowers.empty() || t <= *lowers.begin()) lowers.insert(t);
      else uppers.insert(t);
    } else {
      if (sk.empty()) {
        printf("Invalid\n");
      } else {
        printf("%d\n", midv);
      }
    }
    shrink();
  }
}