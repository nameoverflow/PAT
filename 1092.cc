#include <unordered_set>
#include <iostream>
#include <string>

using namespace std;

int main() {
  unordered_multiset<char> target;
  string t, n;
  cin >> t >> n;
  int miss = 0;
  target.insert(t.begin(), t.end());
  for (auto c : n) {
    auto it = target.find(c);
    if (it != target.end()) {
      // cout << c << endl;
      target.erase(it);
    } else miss++;
  }
  if (miss) {
    cout << "No " << miss;
  } else cout << "Yes " << target.size();
}