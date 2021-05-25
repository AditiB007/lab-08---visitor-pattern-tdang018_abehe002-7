#ifndef __LATEX_H__
#define __LATEX_H__

#include <iostream>
#include "rand.h"

class Op;
// class Rand;
class Add;
class Sub;
class Mult;
class Div;
class Pow;

using namespace std;

class Latex: public Visitor {
  private:
    string output;

  public:
    ~Latex() = default;

    string getOutput() {
      return output;
    }

    void append(string toappend) {
      output += toappend;
    }
    
    void visit_op(Op* op) {
      output += op->stringify();
    }

    void visit_rand(Rand* rand) {
      output += rand->stringify();
    }

    virtual void visit_add_begin(Add* node) {
      append("({");	
    }
    virtual void visit_add_middle(Add* node) { 
      append("}+{");
    }
    virtual void visit_add_end(Add* node) {
      append("})");
    }
    virtual void visit_sub_begin(Sub* node) {
      append("({");
    }
    virtual void visit_sub_middle(Sub* node) {
      append("}-{");
    }
    virtual void visit_sub_end(Sub* node) {
      append("})");
    }
    virtual void visit_mult_begin(Mult* node) {
      append("({");
    }
    virtual void visit_mult_middle(Mult* node) {
      append("}\\cdot{");
    }
    virtual void visit_mult_end(Mult* node) {
      append("})");
    }
    virtual void visit_div_begin(Div* node) {
      append("\\frac{");	
    }
    virtual void visit_div_middle(Div* node) {
      append("}{");
    }
    virtual void visit_div_end(Div* node) {
      append("}");
    }
    virtual void visit_pow_begin(Pow* node) {
      append("({");
    }
    virtual void visit_pow_middle(Pow* node) {
      append("}^{");		
    }
    virtual void visit_pow_end(Pow* node) {
      append("})");
    }
};

string PrintLatex(Base* input) {
  Iterator it(input);
  Latex latex;
  string output;
  while(it.is_done() != true) {
    it.current_node()->accept(&latex, it.current_index());
    it.next();
  }
  output += latex.getOutput();
  return "${" + output + "}$";
}

#endif //__LATEX_H__
