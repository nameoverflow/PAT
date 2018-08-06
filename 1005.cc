#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <climits>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define LOG(__t) cout << ""#__t": " << __t << endl

#define MAXN (100+10)


int main() {
  ull sum = 0;
  int i = 0;
  char disp[][20] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
  };
  string num;
  cin >> num;
  for (auto &c : num) {
    sum += c - '0';
  }

  string res = to_string(sum);
  printf("%s", disp[res[0] - '0']);
  for (int i = 1; i < res.length(); i++) {
    printf(" %s", disp[res[i] - '0']);
  }
}