#ifndef __DIV_HPP__
#define __DIV_HPP__

#include "op.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

class Div: public Base {
  public:

    Base* b1;
    Base* b2;

    Div(Base* a, Base* b) {
      b1 = a;
      b2 = b;
    }

    ~Div() {
      delete b1;
      delete b2;
    }

    double evaluate() {
      if(b2->evaluate() != 0){ return b1->evaluate() / b2->evaluate(); }
      else { throw std::domain_error("divide by zero"); }
    }

    std::string stringify() {
      return "(" + b1->stringify() + " / " + b2->stringify() + ")";
    }

    int number_of_children() {
      return 2;
    }

    Base* get_child(int i) {
      if(i == 0) {
        return b1;
      }
      else {
        return b2;
      }
    }

    void accept(Visitor* visitor, int index) {
      if(index  == 0) {
        visitor->visit_add_begin(this);
      }
      else if(index == 1) {
        visitor->visitor_add_middle(this);
      }
      else {
        visitor->visitor_add_end(this);
      }
    }
};

#endif // __DIV_HPP__

