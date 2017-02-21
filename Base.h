/* 
  BASE Implements the essential elements to support 
  ARRAY based data structures i.e. Dynamic Array, Stack
*/

#ifndef BASE_H
#define BASE_H

#define D_SIZE 2

class Base {
  public:
  /* Custom CTOR - CONSTRUCTOR 0*/
  Base() { 
    (*this)._temp = new uint16_t[D_SIZE];
    (*this)._sizedAt = D_SIZE;
  };

  Base(uint16_t _init, uint16_t _s) { 
    (*this)._temp = new uint16_t[_s];
    (*this)._sizedAt = _s;
    (*this)._temp[_index++] = _init;
  };

  uint16_t getIndex() { return (*this)._index; };
  uint16_t getSizedAt() { return (*this)._sizedAt; };
  boolean isEmpty() { return ((*this)._index == 0 ? 1 : 0); }
  void incrementIndex() { (*this)._index++};
  void decrementIndex() { (*this)._index--};
  
  /* VOLATILE MEANS OVERRIDE THESE METHODS IN SUB CLASSES - AS YOU NEED :) */
  volatile void stats() { 
    Serial.println("Printing Stats - "); 
    Serial.print("Init Array Size: "); Serial.println((*this)._sizedAt);
    if( !isEmpty() ) { 
      for(int i = 0; i < (*this)._index; i++) {
        Serial.print("Element: "); Serial.print((char) i); Serial.print(" "); 
        Serial.println((*this)._temp[i]);
      }
    }
  
  //resize dynamically manages the size of the array
  volatile void resize() { 
     if ((*this)._index < (*this)._sizedAt/2) {
      (*this)._sizedAt /= 2;
     } else if ((*this)._index > (*this)._sizedAt) {
      (*this)._sizedAt *= 2;
    }
  };
  
  //inserts a given new value at the end of the array
  volatile void insert(uint16_t newValue) { 
    insertAt(newValue, (*this)._index);
  };
  
  //inserts a given a value at a particular index
  volatile void insertAt(uint16_t newValue, uint16_t givenIndex) { 
    //for all the values entered at the current index and after 
    // while going through them in reverse
    for (uint16_t i = (*this)._index; i >= givenIndex; i--) {
      //transfers their value into the next index
       (*this)._temp[i+1] = (*this)._temp[i];
    }
    resize();
    (*this)._temp[(*this)._index++] = newValue; 
  };
  
  volatile void remove() {
    removeAt((*this)._index);
    resize();
  };
  
  volatile void removeAt(uint16_t newIndex) { 
    for (uint16_t i = newIndex; i < (*this)._sizedAt; i++) {
       uint16_t storedValue = (*this)._temp[i+1];
       (*this)._temp[i] = storedValue;
    }
    resize();
  };
  
  ~Base() { delete[] (*this)._temp; }
  
  private:
  uint16_t * _temp;
  uint16_t _sizedAt = 0;
  uint16_t _index = 0;
};

#endif // BASE_H
