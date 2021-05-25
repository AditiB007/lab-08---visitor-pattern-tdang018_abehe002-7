#include <iostream>
#include "base.hpp"
#include "div.h"
#include "mult.h"
#include "add.h"
#include "pow.h"
#include "sub.h"
#include "op.hpp"
#include "visitor.hpp"
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
   
  string str1 = PrintLatex(test1);
  string str2 = PrintLatex(test2);
  string str3 = PrintLatex(test3);

  cout << str1 << endl;
  cout << str2 << endl;
  cout << str3 << endl;
    
  return 0;
}
