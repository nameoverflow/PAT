#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

using ull = unsigned long long;


ull res[1010] = {0};

int main() {
  int f, n;
  cin >> f >> n;
  res[0] = 1;
  res[1] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j < i; j++) {
      res[i] = (res[i] + res[j] * res[i - j - 1]) % 1000000007;
    }
  }

  cout << res[n];
}