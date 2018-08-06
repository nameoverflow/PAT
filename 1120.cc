#include <set>
#include <string>
#include <iostream>

using namespace std;

int main() {
  cin.sync_with_stdio(false);
  set<int> fuck;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string num;
    cin >> num;
    int acc = 0;
    for (auto c : num) {
      acc += c - '0';
    }
    fuck.insert(acc);
  }

  cout << fuck.size() << endl;
  bool flag = 0;
  for (auto v : fuck) {
    if (!flag) {
      cout << v;
      flag = 1;
    } else {
      cout << " " << v;
    }
  }
}
