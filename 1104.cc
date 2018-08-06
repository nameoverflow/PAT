#include <cstdio>

double nn[100500];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &nn[i]);
  }

  double sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (double)(i + 1) * (double)(n - i) * nn[i];
  }
  printf("%.02lf", sum);
}
