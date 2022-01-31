#include "bitset.hpp"
#include <string>

  // TODO COMMENT
Bitset::Bitset() {
  Bitset::bsize = 8;
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {myBitset[i] = 0;}
}

  // TODO COMMENT
Bitset::Bitset(intmax_t size) {
  Bitset::bsize = size;
  myBitset = new u_int8_t[bsize];
  for(int i = 0; i < bsize; i++) {myBitset[i] = 0;}
}

  // TODO COMMENT
Bitset::Bitset(const std::string & value) {

}

  // TODO COMMENT
Bitset::~Bitset() {
  delete [] Bitset::myBitset;
}

  //Bitset(const Bitset & ) = delete;
  //Bitset & operator=(const Bitset &) = delete;

  // TODO COMMENT
  intmax_t Bitset::size() const {

  }

  // TODO COMMENT
  bool Bitset::good() const {

  }

  // TODO COMMENT
  void Bitset::set(intmax_t index) {

  }

  // TODO COMMENT
  void Bitset::reset(intmax_t index) {

  }

  // TODO COMMENT
  void Bitset::toggle(intmax_t index) {

  }

  // TODO COMMENT
  bool Bitset::test(intmax_t index) {

  }

  // TODO COMMENT
  std::string Bitset::asString() const {

  }
