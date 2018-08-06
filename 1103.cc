#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// vector<vector<int>> res;

int pp(int a, int b)
{
  int ans = 1, base = a;
  while (b != 0)
  {
    if (b & 1)
      ans *= base;
    base *= base;
    b >>= 1;
  }
  return ans;
}
vector<int> res;
vector<int> cache;
vector<int> part;
int maxs = 0;

void solve(int n, int k, int p, int sum, int idx)
{
  if (k == 0 && n == 0)
  {
    if (sum > maxs)
    {
      maxs = sum;
      res = part;
    }
    return;
  }
  if (k < 0 && n < 0)
    return;
  if (idx >= 1) {
    part.push_back(idx);
    solve(n - cache[idx], k - 1, p, sum + idx, idx);
    part.pop_back();
    solve(n, k, p, sum, idx - 1);
  }
}

int main()
{
  int n, k, p;
  cin >> n >> k >> p;
  vector<int> part;
  res.reserve(n);
  part.reserve(n);

  for (int maxi = 0;; maxi++)
  {
    cache.push_back(pow(maxi, p));
    if (cache[maxi] > n - k + 2)
      break;
  }

  solve(n, k, p, 0, cache.size() - 1);

  if (res.empty())
  {
    cout << "Impossible";
    return 0;
  }

  cout << n << " = " << res[0] << "^" << p;
  for (int i = 1; i < res.size(); i++)
  {
    cout << " + " << res[i] << "^" << p;
  }
}
