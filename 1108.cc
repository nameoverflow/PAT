#include <string>
#include <vector>
#include <cctype>
#include <cstdio>

using namespace std;

bool check(string &n) {
  int point = 0;
  if (n == "-") return false;
  if (!isdigit(n[0]) && n[0] != '-') {
    return false;
  }
  for (int i = n[0] == '-' ? 1 : 0; i < n.size(); i++) {
    if (!isdigit(n[i])) {
      if (n[i] == '.') {
        if (point == 0) point = 1;
        else return false;
      } else return false;
    } else {
      if (point > 0) point++;
      if (point > 3) return false;
    }
  }
  return true;
}

char buff[1010] = {0};
int main() {
  int n;
  int count = 0;
  double sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", buff);
    double n;
    string t(buff);
    if (!check(t) || (sscanf(buff, "%lf", &n), (n > 1000 || n < -1000))) {
      printf("ERROR: %s is not a legal number\n", buff);
    } else {
      sum += n;
      count ++;
    }
  }
  if (count == 1) {
    printf("The average of 1 number is %.2lf", sum);
  } else if (count) {
    printf("The average of %d numbers is %.2lf", count, sum / count);
  } else {
    printf("The average of 0 numbers is Undefined");
  }
}
