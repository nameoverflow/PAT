#include <utility>
#include <cstdio>
#include <string>
#include <iostream>
#include <cctype>
#include <stack>

using namespace std;

int pred(char op) {
  switch (op) {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    default:
      return -1;
  }
}

double calu(char op, double l, double r) {
  switch (op) {
    case '+': return l + r;
    case '-': return l - r;
    case '*': return l * r;
    case '/': return l / r;
  }
}



stack<char> op;
stack<double> num;
void eval() {
  double r = num.top(); num.pop();
  double l = num.top(); num.pop();
  // printf("calu %lf %c %lf\n", l, op.top(), r);
  num.push(calu(op.top(), l, r));
  op.pop();
}
int main() {
  string tk;
  char cc;

  string exp;
  cin >> exp;
  for (auto c : exp) {
    if (isdigit(c)) {
      tk += c;
    } else {
      if (isdigit(tk[0])) {
        num.push(stoi(tk));
        tk = "";
      }
      if (c == '(') {
        op.push(c);
      } else if (c == ')') {
        while (op.top() != '(') eval();
        op.pop();
      } else {
        if (op.size() && pred(op.top()) >= pred(c)) {
          while (op.size() && pred(op.top()) >= pred(c)) {
            eval();
          }
        }
        op.push(c);
      }
    }
  }
  // printf("%s\n", tk.c_str());
  if (isdigit(tk[0])) {
    num.push(stoi(tk));
    tk = "";
  }

  if (num.size() > 1) eval();
  printf("%.2lf", num.top());


}