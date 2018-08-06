#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <functional>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>


using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define upto(_d1, _d2) _d1 = _d1 < d2 ? _d2 : _d1;
#define downto(_d1, _d2) _d1 = _d1 > d2 ? _d2 : d1;
#define subabs(_d1, _d2) (_d1 < _d2 ? _d2 - _d1 : d1 - d2)

#define LOG(__t) cout << ""#__t": " << __t << endl

template<typename It>
ll diff(It st, It mid, It ed) {
  ll d = 0;
  auto c = mid;
  while (st != mid) {
    d += *c - *st;
    st++; c++;
  }
  if (c != ed) {
    // LOG(*(mid));
    if (*mid < 0) {
      d -= *mid * 2;
    }
    d += *c;
  }
  return abs(d);
}

int main() {
  ull N;
  scanf("%lld", &N);
  vector<ll> nums(N);
  for (ull i = 0; i < N; i++) {
    scanf("%lld", &nums[i]);
  }
    nth_element(nums.begin(), nums.begin() + (N / 2), nums.end());
    auto d = diff(nums.begin(), nums.begin() + (N / 2), nums.end());
    printf("%d %lld",N % 2, d);
}
