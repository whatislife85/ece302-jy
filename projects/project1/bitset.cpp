#include "bitset.hpp"
#include <string>
#include <stdio.h>
#include <stdlib.h>

  // TODO COMMENT
Bitset::Bitset() {
  valid = true;
  Bitset::bsize = 8;
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {myBitset[i] = 0;}
}

  // TODO COMMENT
Bitset::Bitset(intmax_t size) {
  if(size <= 0) {
    valid = false;
    return;
  }
  Bitset::bsize = size;
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {myBitset[i] = 0;}
}

  // TODO COMMENT
Bitset::Bitset(const std::string & value) {
  Bitset::bsize = value.length();
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {
    if(value[i] == '0') {myBitset[i] = 0;}
    else if(value[i] == '1') {myBitset[i] = 1;}
    else {valid = false; return;}
  }
}

  // TODO COMMENT
Bitset::~Bitset() {
  delete [] Bitset::myBitset;
}

  // TODO COMMENT
  intmax_t Bitset::size() const {
    return bsize;
  }

  // TODO COMMENT
  bool Bitset::good() const {
    return valid;
  }

  // TODO COMMENT
  void Bitset::set(intmax_t index) {
   if(index < 0 || index >= bsize) {valid = false; return;}
   myBitset[index] = 1;
  }

  // TODO COMMENT
  void Bitset::reset(intmax_t index) {
    if(index < 0 || index >= bsize) {valid = false; return;}
    myBitset[index] = 0;
  }

  // TODO COMMENT
  void Bitset::toggle(intmax_t index) {
    if(index < 0 || index >= bsize) {valid = false; return;}
    myBitset[index] ^= myBitset[index];
  }

  // TODO COMMENT
  bool Bitset::test(intmax_t index) {
    if(index < 0 || index >= bsize) {valid = false; return false;}
    if(myBitset[index]) {return true;}
    else {return false;}
  }

  // TODO COMMENT
  std::string Bitset::asString() const {
    std::string myBitsetStr;
    for(int i = 0; i < bsize; i++) {
      if(myBitset[i]) {myBitsetStr += "1";}
      else {myBitsetStr += "0";}
    }
    return myBitsetStr;
  }
