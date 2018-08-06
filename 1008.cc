#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define LOG(__t) cout << ""#__t": " << __t << endl

typedef long long ll;

int main() {
  int cur = 0;
  int sum = 0;
  int total = 0;
  scanf("%d", &total);

  for (int i = 0; i < total; i++) {
    int next;
    scanf("%d", &next);
    int sub = cur - next;
    if (sub < 0) {
      sum -= sub * 6;
    } else {
      sum += sub * 4;
    }
    sum += 5;
    cur = next;
  }
  printf("%d", sum);
}