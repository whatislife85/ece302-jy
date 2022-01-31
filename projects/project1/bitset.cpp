#include "bitset.hpp"
#include <string>
#include <stdio.h>
#include <stdlib.h>

  //constructs valid bitset of size 8 with all bits set to 0
Bitset::Bitset() {
  valid = true;
  Bitset::bsize = 8;
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {myBitset[i] = 0;}
}

  //constructs valid bitset of size 'size' with all bits set to 0
Bitset::Bitset(intmax_t size) {
  if(size <= 0) {
    valid = false;
    return;
  }
  valid = true;
  Bitset::bsize = size;
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {myBitset[i] = 0;}
}

  //constructs valid bitset from string array of 1's and 0's
Bitset::Bitset(const std::string & value) {
  Bitset::bsize = value.length();
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {
    if(value[i] == '0') {myBitset[i] = 0;}
    else if(value[i] == '1') {myBitset[i] = 1;}
    else {valid = false; return;}
  }
  valid = true;
}

  //deconstructs Bitset object and deallocates memory
Bitset::~Bitset() {
  delete [] Bitset::myBitset;
}

  //returns size of bitset
  intmax_t Bitset::size() const {
    return bsize;
  }

  //returns true if bitset is valid, false otherwise
  bool Bitset::good() const {
    return valid;
  }

  //sets 'index' bit value to 1
  void Bitset::set(intmax_t index) {
   if(index < 0 || index >= bsize) {valid = false; return;}
   myBitset[index] = 1;
  }

  //resets 'index' bit value to 0
  void Bitset::reset(intmax_t index) {
    if(index < 0 || index >= bsize) {valid = false; return;}
    myBitset[index] = 0;
  }

  //toggles 'index' bit value
  void Bitset::toggle(intmax_t index) {
    if(index < 0 || index >= bsize) {valid = false; return;}
    myBitset[index] = 1 ^ myBitset[index];
  }

  //checks if 'index' bit is set, returns true if yes and false if not
  bool Bitset::test(intmax_t index) {
    if(index < 0 || index >= bsize) {valid = false; return false;}
    if(myBitset[index]) {return true;}
    else {return false;}
  }

  //returns bitset as a string of digits from left-to-right
  std::string Bitset::asString() const {
    std::string myBitsetStr;
    for(int i = 0; i < bsize; i++) {
      if(myBitset[i]) {myBitsetStr += "1";}
      else {myBitsetStr += "0";}
    }
    return myBitsetStr;
  }
