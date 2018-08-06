#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
  vector<ll> s1, s2;
  int n1, n2;
  scanf("%d", &n1);
  s1.reserve(n1);
  for (int i = 0; i < n1; i++) {
    int m;
    scanf("%lld", &m);
    s1.push_back(m);
  }
  scanf("%d", &n2);
  s2.reserve(n2);
  for (int i = 0; i < n2; i++) {
    int m;
    scanf("%lld", &m);
    s2.push_back(m);
  }
  int nn = n1 + n2;
  vector<ll> s3(nn);
  merge(s1.begin(), s1.end(), s2.begin(), s2.end(), s3.begin());
  int mid = nn % 2 == 0 ? (nn - 1) / 2 : nn / 2;
  printf("%lld", s3[mid]);
}
