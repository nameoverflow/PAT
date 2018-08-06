#include <string>
#include <set>
#include <iostream>

using namespace std;
#define LOG(__t) cout << ""#__t": " << __t << endl

int main() {
  int dig[10][2] = {0};
  char n[22];
  string n1;
  cin >> n1;

  for (auto c : n1) {
    dig[c - '0'][0]++;
  }

  int add = 0;
  for (int i = n1.size() - 1; i >= 0; i--) {
    int t = n1[i] - '0';
    t *= 2;
    t += add;
    add = 0;
    if (t > 9) {
      add = t / 10;
      t %= 10;
    }
    n1[i] = t + '0';
  }

  if (add != 0) {
    cout << "No" << '\n';
    cout << add << n1;
    return 0;
  }


  for (auto c : n1) {
    dig[c - '0'][1]++;
  }

  bool res = true;
  for (int i = 0; i < 10; i++) {
    res = res && dig[i][1] == dig[i][0];
  }

  cout << (res ? "Yes" : "No") << '\n' << n1;
}
