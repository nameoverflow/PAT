#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

#define LOG(__t) cout << ""#__t": " << __t << endl

typedef long long ll;

ll nums[10000 + 10];

int main() {
  ll cur;
  int num;
  scanf("%d", &num);

  for (int i = 0; i < num; i++) {
    scanf("%lld", &nums[i]);
  }
  ll start = 0;
  ll startm = 0;
  ll endm = 0;
  ll sum = 0;
  ll msum = nums[0];
  for (int i = 0; i < num; i++) {
    sum += nums[i];
    if (sum > msum) {
      startm = start;
      endm = i;
      msum = sum;
    }
    if (sum < 0) {
      start = i + 1;
      sum = 0;
    }
  }
  if (msum < 0) {
  printf("%d %d %d", 0, nums[0], nums[num - 1]);
  } else {
  printf("%d %d %d", msum, nums[startm], nums[endm]);
  }

}