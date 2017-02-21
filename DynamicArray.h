#include "Base.h"

#ifndef DYNAMIC_H
#define DYNAMIC_H

class DynamicArray: public Base {
  public:
  /* Default CTOR - CONSTRUCTOR 0*/
  DynamicArray():Base() { };
  DynamicArray(uint16_t _init, uint16_t _s = 2):Base(_init, _s) { };

  /* UNCOMMENT THIS TO SEE WHAT HAPPENS */
  
  void insert(uint16_t newValue) {
    insertAt(newValue, getIndex());
   };

  void insertAt(uint16_t newValue, uint16_t givenIndex) { 
    //for all the values entered at the current index and after 
    // while going through them in reverse
    for (uint16_t i = getIndex(); i >= givenIndex; i--) {
      //transfers their value into the next index
       (*this)._temp[i+1] = (*this)._temp[i];
    }
    resize();
     (*this)._temp[givenIndex] = newValue; 
     incrementIndex();
   };

   void remove() {
    removeAt(getIndex());
    resize();
  };

  void removeAt(uint16_t newIndex) { 
    for (uint16_t i = newIndex; i < getSizedAt(); i++) {
       uint16_t storedValue = (*this)._temp[i+1];
       (*this)._temp[i] = storedValue;
    }
    resize();
  };
  
  
  
  private:
};

#endif // DYNAMIC_H
