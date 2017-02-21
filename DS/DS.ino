#include "DynamicArray.h"
#include "Stack.h"

// Default Constructor - Initial Array Size of 2
DynamicArray da;
Stack sa;

//// Custom Constructor - Initial Array Size of 2 and first insert 10
DynamicArray db(10);
//
//// Custom Constructor - Initial Array Size of 255 and first insert 100
DynamicArray dc(100, 255);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  da.stats();
  Serial.println();
  sa.stats();
  Serial.println();
  dc.stats();
  Serial.println();
  da.insert(1000);
  da.remove();
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
