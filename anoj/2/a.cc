#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
  double a, x, y, b, h;
  cin >> a >> x >> y >> b >> h;
  double dx = b - a;
  double c2 = 4 * y / x;
  double c1 = -1 * c2 / x;
  double fly = c1 * pow(dx, 2) + c2 * dx;
  cout << ((fly - h > 1e-2 || fly < 0) ? "YES" : "NO");
}