#include <string>
#include <iostream>
#include <cinttypes>

using namespace std;

int main() {
  uint32_t num;
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    string sn = to_string(num);
    string p1(sn.begin(), sn.begin() + sn.size() / 2);
    string p2(sn.begin() + sn.size() / 2, sn.end());
    int n2 = stoi(p1);
    int n3 = stoi(p2);
    if (n2 * n3 != 0 && num % (n2 * n3) == 0) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  }
}
