#ifndef __POW_HPP__
#define __POW_HPP__

#include "op.hpp"
#include "visitor.hpp"
#include "iterator.hpp"

class Pow: public Base {
  public:

    Base* b1;
    Base* b2;

    Pow(Base* a, Base* b) {
      b1 = a;
      b2 = b;
    }

    ~Pow() {
      delete b1;
      delete b2;
    }

    double evaluate() {
      double result = 1;
      double num1 = b1->evaluate();
      double num2 = b2->evaluate();
      if(num2 < 0) {
        num1 = 1/(num1);
        num2 = (num2)/-1;
      }
      for(int i = 0; i < num2; i++) {
        result *= num1;  
      }
      return result;
    }

    std::string stringify() {
      return "(" + b1->stringify() + " ** " + b2->stringify() + ")";
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

#endif // __ADD_HPP__

