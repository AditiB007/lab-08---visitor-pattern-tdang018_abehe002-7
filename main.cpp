#include <iostream>
#include "base.h"
#include "div.h"
#include "mult.h"
#include "add.h"
#include "pow.h"
#include "sub.h"
#include "op.hpp"
#include "visitor.h"
#include "iterator.cpp"
#include "latex.h"

using namespace std;

int main() {
  Base* one = new Op(1);
  Base* two = new Op(2);
  Base* three = new Op(3);

  Base* test1 = new Div(three, two);
  Base* test2 = new Div(three, test1);
  Base* test3 = new Div(test1, one);
   
  string str1 =PrintLaTeX(test1);
  string str2 =PrintLaTeX(test2);
  string str3 =PrintLaTeX(test3);

  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
    
  return 0;
}
