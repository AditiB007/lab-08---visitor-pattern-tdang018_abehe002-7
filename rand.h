#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "op.hpp"
#include <stdlib.h>
#include <time.h>
#include "visitor.hpp"
#include "iterator.hpp"

class Rand: public Base {
  private:
    int value;

  public:

    Rand() {
      srand(time(0));
      value = rand() % 100;
    }
    Rand(int seed) {
      srand(seed);
      value = rand() % 100;
    }

    ~Rand() {
      
    }

    double evaluate() {
      return value;
    }

    std::string stringify() {
      return std::to_string(value);
    }

    virtual int number_of_children() {
      return 0;
    }
    virtual Base* get_child(int i) {
      return nullptr;
    }
    virtual void accept(Visitor* visitor, int index) {
      visitor->visit_rand(this);
    }
};

#endif // __MULT_HPP__

