#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <functional>

using namespace std;

typedef unsigned long long ull;

#define LOG(__t) cout << ""#__t": " << __t << endl

typedef union cvrt {
  char name[6];
  int hash;
} cvrt;

int main() {
  int N, K;
  scanf("%d %d", &N, &K);

  unordered_map<int, priority_queue<int, vector<int>, greater<int> > > stus;
  
  for (size_t i = 0; i < K; i++) {
    int idx, reg;
    scanf("%d %d", &idx, &reg);

    for (size_t r = 0; r < reg; r++) {
      cvrt stu;
      scanf("%s", &stu.name);
      stus[stu.hash].push(idx);
    }
  }

  for (size_t i = 0; i < N; i++) {
    cvrt stu;
    scanf("%s", &stu.name);
    printf("%s %d", stu.name, stus[stu.hash].size());

    while (!stus[stu.hash].empty()) {
      printf(" %d", stus[stu.hash].top());
      stus[stu.hash].pop();
    }
    printf("\n");
  }
}