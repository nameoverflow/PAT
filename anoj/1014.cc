#include <cmath>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

using ull = unsigned long long;

inline bool solve(string n) {
  if (n == "120") return true;
  ull sum = 0;
  for (auto c : n) {
    sum += c - '0';
  }
  if (sum == 120) return true;
  sum = 0;
  for (auto c : n) {
    sum += (c - '0') * (c - '0');
  }
  if (sum == 120) return true;
  return false;
}

int main() {
  string n;
  cin >> n;
  puts(solve(n) ? "YES" : "NO");
}
