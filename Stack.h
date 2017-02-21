#include "Base.h"

#ifndef STACK_H
#define STACK_H

class Stack: public Base {
  public:
  /* Default CTOR - CONSTRUCTOR 0*/
  Stack():Base() { };
  Stack(uint16_t _init, uint16_t _s = 2):Base(_init, _s) { };

  /* UNCOMMENT THIS TO SEE WHAT HAPPENS */
  //void push(uint16_t) { Serial.print("pushed"); };
  //void pop() { Serial.print("popped"); };
  //void peek() { Serial.print("peeked"); };
  //void void stats() {};
  
  private:
};

#endif // STACK_H
