#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

char buf[40];
unsigned long long cc[40] = {0};

int main() {
  int n;
  scanf("%d", &n);

  unsigned long long count = 0;

  int no = 1;
  while (no <= n) {
    int h = n / no / 10;
    int l = n % no;
    int c = (n / no) % 10;
    count += no * h;
    count += (c == 1) * (l + 1);
    count += (c > 1) * no;
    no *= 10;
  }

  printf("%llu", count);
  
}