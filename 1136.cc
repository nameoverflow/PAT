#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

#define LOG(__t) cout << ""#__t": " << __t << endl
bool isp(string &n) {
  int k = n.size() - 1;
  bool res = true;
  for (int i = 0; i < n.size() / 2; i++) {
    res = res && n[i] == n[k - i];
  }
  return res;
}

int main() {
  string num;
  cin >> num;

  if (isp(num)) {
    cout << num << " is a palindromic number.\n";
    return 0;
  }
  for (int _ = 0; _ < 10; _++) {
    cout << num << " + ";
    string rnum(num);
    reverse(rnum.begin(), rnum.end());
    cout << rnum << " = ";
    for (auto &c : num) {
      c -= '0';
    }
    for (auto &c : rnum) {
      c -= '0';
    }
    int add = 0;
    for (int i = 0; i < num.size(); i++) {
      num[i] += rnum[i] + add;
      add = num[i] / 10;
      num[i] %= 10;
    }
    if (add) num.push_back((char)add);
    for (auto &c : num) {
      c += '0';
    }
    reverse(num.begin(), num.end());
    cout << num << '\n';
    if (isp(num)) {
      cout << num << " is a palindromic number.\n";
      return 0;
    }
  }
  cout << "Not found in 10 iterations.\n";
}

