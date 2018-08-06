#include <cstdio>
#include <climits>

int main() {
  int idx[3] = {0};
  double odd[3] = {0};
  double set[3] = {0};
  char disp[] = "WTL";

  for (int i = 0; i < 3; i++) {
    scanf("%lf %lf %lf", &odd[0], &odd[1], &odd[2]);
    int maxi = 0;
    for (int j = 0; j < 3; j++) {
      if (odd[maxi] < odd[j]) {
        maxi = j;
      }
    }
    idx[i] = maxi;
    set[i] = odd[maxi];
  }

  printf("%c %c %c %.2lf", disp[idx[0]], disp[idx[1]], disp[idx[2]], (set[0] * set[1] * set[2] * 0.65 - 1) * 2 + 0.0049);
}