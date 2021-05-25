#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "op.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

class Sub: public Base {
  public:

    Base* b1;
    Base* b2;

    Sub(Base* a, Base* b) {
      b1 = a;
      b2 = b;
    }

    ~Sub() {
      delete b1;
      delete b2;
    }

    double evaluate() {
      return b1->evaluate() - b2->evaluate();
    }

    std::string stringify() {
      return "(" + b1->stringify() + " - " + b2->stringify() + ")";
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
        visitor->visit_add_middle(this);
      }
      else {
        visitor->visit_add_end(this);
      }
    }
};

#endif // __Sub_HPP__

